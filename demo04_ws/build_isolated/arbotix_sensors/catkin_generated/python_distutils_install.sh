#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/jy/demo04_ws/src/arbotix_ros/arbotix_sensors"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/jy/demo04_ws/install_isolated/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/jy/demo04_ws/install_isolated/lib/python3/dist-packages:/home/jy/demo04_ws/build_isolated/arbotix_sensors/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/jy/demo04_ws/build_isolated/arbotix_sensors" \
    "/usr/bin/python3" \
    "/home/jy/demo04_ws/src/arbotix_ros/arbotix_sensors/setup.py" \
     \
    build --build-base "/home/jy/demo04_ws/build_isolated/arbotix_sensors" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/jy/demo04_ws/install_isolated" --install-scripts="/home/jy/demo04_ws/install_isolated/bin"

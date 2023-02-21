#!/bin/sh


xterm -e "source devel/setup.bash && roslaunch my_robot world.launch" &

sleep 15

xterm -e "source devel/setup.bash && roslaunch my_robot amcl.launch map_file:=${path_catkin_ws}/src/map/map.yaml" &


sleep 5

xterm -e "source devel/setup.bash && rosrun add_markers_solo add_markers_solo"


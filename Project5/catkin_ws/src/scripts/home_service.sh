#!/bin/sh


xterm -e "source devel/setup.bash && roslaunch my_robot world.launch" &

sleep 30

xterm -e "source devel/setup.bash && roslaunch my_robot amcl.launch map_file:=${path_catkin_ws}/src/map/map.yaml" &

sleep 30


xterm -e "source devel/setup.bash && rosrun add_markers add_markers" &

sleep 5

xterm -e "source devel/setup.bash && rosrun pick_objects pick_objects" 

s




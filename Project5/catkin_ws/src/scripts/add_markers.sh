#!/bin/sh
path_catkin_ws="$(cd $(dirname "$0")/../..> /dev/null && pwd)"


xterm -e "cd ${path_catkin_ws} && source ~/.bashrc && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=${path_catkin_ws}/src/my_robot/worlds/world.world" &

sleep 30

xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo amcl_demo.launch map_file:=${path_catkin_ws}/src/map/map.yaml" &

sleep 30

xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun rviz rviz -d ${path_catkin_ws}/src/rvizConfig/home_service_rvizConfig.rviz" &

sleep 10

xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun add_markers_solo add_markers_solo"


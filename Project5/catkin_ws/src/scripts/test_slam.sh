#!/bin/sh


xterm -e "source devel/setup.bash && roslaunch my_robot world.launch" &

sleep 5

xterm -e "source devel/setup.bash && roslaunch my_robot gmapping.launch" &


sleep 5

xterm -e "source devel/setup.bash && roslaunch turtlebot_teleop keyboard_teleop.launch" 




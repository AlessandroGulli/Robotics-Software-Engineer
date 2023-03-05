

### Introduction
   - Aim of the final project was to combine what has been learned in the entire program to simulate a home service robot that can map, localize, and navigate to transport objects, moving from one point to another. 
   
### Overview
   - The turtlebot robot drives aroung the environment for mapping using `gmapping` package and create an **occupancy grid map**. After having the map, it uses laser range finder and odometry data to localize itself itself by utilizing **Adaptive Monte Carlo Localization (AMCL)**. User can predefine the pick-up and delivery points for the robot, and it uses those navigation goals to autonomously plans trajectory using **Dijikstra algorithm** to accomplish the task. 
   
### Tested on:
   - Ubuntu 18.04
   - ROS Kinetic
   - Rviz
   - Gazebo

### Pre-Requisite: 
   - Install xterm: `sudo apt-get install xterm`
   - To load map (pgm file) (optional): `sudo apt-get install ros-${ROS_DISTRO}-map-server`
   - Localization algorithm: `sudo apt-get install ros-${ROS_DISTRO}-amcl`
   - ROS navigation package: `sudo apt-get install ros-${ROS_DISTRO}-move-base`
   - ROS gmapping package: `sudo apt-get install ros-${ROS_DISTRO}-slam-gmapping`
   
### Mapping
   - Performed using ROS [gmapping] package
   - This section creates a map of the environment using Grid SLAM algorithm, generating an occupancy grid map (from pgm file) which would be used for localization and navigation tasks.
   - Run `test_slam.sh` to create occupancy grid map.
 

### Localization and Navigation
   - Performed using ROS [amcl] package  
   - Robot localization is the process of determining where a mobile robot is located with respect to its environment. Here AMCL package is used to localize the robot in the environment.
   - Run `test_navigation.sh` to navigate around the map by providing 2D Nav Goal from Rviz

### Path planning
   - Performed using ROS [move_base] package
   - The path planning and navigation was done using the turtlebot_gazebo package, based on Dijkstra's shortest path algorithm, which is a variant of the Uniform Cost Search algorithm. Using a path planning package like this permits a robot to avoid any encountered obstacles in its path by re-planning a new trajectory.
   - Run `home_service.sh` which initiate robot pick-up location and drop-off location, and the robot will plan its trajectory automatically
   
### **How to run**:
      1. Terminal 1: `./home_service.sh` from the scripts directory (catkin_ws/src/scripts).
###  3. **Where Am I?** (Localization)
   - Use the Monte Carlo Localization algorithm in ROS, in conjunction with sensor data and a map of the world, to estimate a mobile robot’s position and orientation so that robot can answer the question “Where am I?” Skills apply: Localization algorithms: Kalman Filter and MCL, ROS parameters, ROS packages integration, C++.
   
   - **How to run**:
      1. Terminal 1: `roslaunch my_robot world.launch`
      2. Terminal 2: `roslaunch my_robot amcl.launch`
    
   - **Final output**:
   
![Animation](https://user-images.githubusercontent.com/29335742/222954973-0c81d4d5-26a6-47d0-a507-ef230b77d4e6.gif)

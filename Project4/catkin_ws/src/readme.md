###  4. **Map My World** (Mapping and SLAM)
   - Simultaneous Localization and Mapping (SLAM) can be implemented in a number of ways depending on the sensors used via various ROS packages. Use a ROS SLAM package and simulated sensor data to create an agent that can both map the world around it, and localize within it. Skills apply: Mapping and SLAM algorithms, Occupancy Grid Mapping, Grid-based FastSLAM and GraphSLAM, ROS debugging tools, C++.

   - **How to run**:
      1. Terminal 1: `roslaunch my_robot world.launch`
      2. Terminal 2: `roslaunch my_robot teleop.launch`
      3. Terminal 3: `roslaunch my_robot mapping.launch`
    
   - **Final output**:
   
![image](https://user-images.githubusercontent.com/29335742/222954842-aafcb2a2-738f-4d7a-a9a8-d565d6a12fa2.png)

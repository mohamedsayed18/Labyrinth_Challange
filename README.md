# Labyrinth_Challange
GSoC-2020 JdeRobot- C++ Challange

The code try to find the longest pathway in a labyrinth like this
```
##.##.#
#..##.#
#.#####
#..####
#######
```
Desired output
```
##0##.#
#21##.#
#3#####
#45####
#######
```
### Run the code
Build the code using these commands<br/>
`cmake .`<br/>
`make`<br/>
Launch the application<br/>
`/.labyrinth`<br/>

### Algorithm
* First assign weight of zero to all possible points<br/>
* Find the highest and not visited point<br/>
* Assign new weights to its available neighbors (point_weight + 1)<br/>
* Repeat the last two steps until all points are visited<br/>
* back track and display the pathway<br/>

### Files
* data.txt, data2.txt contain the labyrinth
* demo.cpp the main code
* CMakeLists.txt to build 

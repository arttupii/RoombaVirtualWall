Roomba iRobot virtualwall


 - For Roomba 500, 600, 700, 800 and 900 series
 - Uses two AA battery (2x1.5V=3V)
 - ATTINY85 Microcontroller


```
     <----------490us and 19 pulses----------------->
     <---25us---->                                   <--- 130ms (power down      ) ---->
     
     |-----|     |-----|          |-----|     |-----|                                   |------|
     |     |     |     |          |     |     |     |                                   |      |
     |     |     |     |          |     |     |     |                                   |      |
     |     |     |     |          |     |     |     |                                   |      |
_____|     |_____|     |_____.....|     |_____|     |_______________......______________|      |____
```

R1=47R

R2=200R

VCC=2x1.5V(AA battery) = 3V

![alt text](https://raw.githubusercontent.com/arttupii/RoombaVirtualWall/master/Pictures/schematic.PNG)



![alt text](https://raw.githubusercontent.com/arttupii/RoombaVirtualWall/master/Pictures/case.PNG)

![alt text](https://github.com/arttupii/RoombaVirtualWall/raw/master/Pictures/VirtualWall.PNG)



#pragma once

// NOTES FOR CAMERA CLASS 
// This class should handle the view-transformations based on the camera positiond
// input: Matrix, Window-size 
// methods: access data dimentions, get height at given point, get a 2d-render of a given sceene (downsample)
// put simply: given a camera angle, what is the view-boundery
//The camera should: calculate a transformation (projection matrix) based on camera-angle -> The renderer should only care about rendering what the camera says it should render

#pragma once

// NOTES FOR HEIGHTMAP CLASS 
// This class should handle the data and mathematical operations related to the height matrix
// input: Matrix, Window-size 
// methods: access data dimentions, get height at given point, get a 2d-render of a given sceene (downsample) This is simply a wrapper fot the GDAL liberary
// could preform the downsample right away in order to reduce the workload of other parts of the code
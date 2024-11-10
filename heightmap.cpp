#include <stdexcept> 
#include "heightmap.h"
#include "gdal_priv.h" 
#include "iostream"


HeightMap::HeightMap(const std::string& path_to_data) {
    GDALAllRegister();
    // Open your DTM file
    GDALDataset *dataset = (GDALDataset *) GDALOpen(path_to_data.c_str(), GA_ReadOnly);
    if (dataset == nullptr) {
        throw std::runtime_error("Failed to open DTM file: " + path_to_data);
    }

    this->width = dataset->GetRasterXSize();
    this->height = dataset->GetRasterYSize();
    
    float *raw_buffer = new float[width * height];

    GDALRasterBand *band = dataset->GetRasterBand(1);
    if (band->RasterIO(GF_Read, 0, 0, width, height, raw_buffer, width, height, GDT_Float32, 0, 0) != CE_None) {
        delete[] raw_buffer;
        GDALClose(dataset);
        throw std::runtime_error("Failed to open DTM file: " + path_to_data);
    }

    this->buffer = std::shared_ptr<float[]>(raw_buffer);

    GDALClose(dataset);
} 


std::shared_ptr<const float[]> HeightMap::getBuffer() const {
    return buffer;
}




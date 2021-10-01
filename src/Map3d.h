#ifndef CITYCFD_MAP3D_H
#define CITYCFD_MAP3D_H

#include "config.h"
#include "io.h"
#include "TopoFeature.h"
#include "Terrain.h"
#include "Building.h"
#include "Boundary.h"
#include "SurfaceLayer.h"

class Map3d {
public:
    Map3d();
    ~Map3d();

    void reconstruct();

    bool read_data();
    void output();

private:
     Point_set_3                  _pointCloud;
     Point_set_3                  _pointCloudBuildings;
     nlohmann::json               _polygonsBuildings;
     std::vector<nlohmann::json>  _polygonsSurfaceLayers;
     Terrain*                     _terrain;
     std::vector<Boundary*>       _boundaries;
     std::vector<PolyFeature*>    _lsFeatures;
     std::vector<TopoFeature*>    _outputFeatures;

    void set_features();
    void set_boundaries();
    void triangulate_terrain();
    void polygon_processing();
    void set_footprint_elevation();
    void threeDfy();
    void prep_feature_output();
    void prep_cityjson_output();
    void collect_garbage();
    void clear_features();
};

#endif //CITYCFD_MAP3D_H
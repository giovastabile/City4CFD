/*
  City4CFD
 
  Copyright (c) 2021-2022, 3D Geoinformation Research Group, TU Delft  

  This file is part of City4CFD.

  City4CFD is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  City4CFD is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with City4CFD.  If not, see <http://www.gnu.org/licenses/>.

  For any information or further details about the use of City4CFD, contact
  Ivan Pađen
  <i.paden@tudelft.nl>
  3D Geoinformation Research Group
  Delft University of Technology
*/

#ifndef CITY4CFD_POINTCLOUD_H
#define CITY4CFD_POINTCLOUD_H

#include "types.h"
#include "CGALTypes.h"

#include "lasreader.hpp"

typedef std::shared_ptr<SearchTree> SearchTreePtr;

class PointCloud {
public:
    PointCloud();
    ~PointCloud();

    void random_thin_pts();
    void create_flat_terrain(const PolyFeatures& lsFeatures);
    void set_flat_terrain();
    void smooth_terrain();
    void flatten_polygon_pts(const PolyFeatures& lsFeatures);
    SearchTreePtr make_search_tree_buildings();
    void read_point_clouds();
    void add_elevation_point(const LASpoint& laspt, const CGAL::Aff_transformation_3<EPICK>& translate);
//    bool check_bounds(const double xmin, const double xmax, const double ymin, const double ymax);

    Point_set_3& get_terrain();
    Point_set_3& get_buildings();
    const Point_set_3& get_terrain() const;
    const Point_set_3& get_buildings() const;

private:
    Point_set_3 _pointCloudTerrain;
    Point_set_3 _pointCloudBuildings;
};


#endif //CITY4CFD_POINTCLOUD_H

[![docs](https://img.shields.io/badge/docs-Wiki-brightgreen)](https://github.com/tudelft3d/City4CFD/wiki)
[![GitHub license](https://img.shields.io/github/license/tudelft3d/City4CFD)](https://github.com/tudelft3d/City4CFD/blob/master/LICENSE)
[![DOI:10.3389/fbuil.2022.899332](http://img.shields.io/badge/DOI-10.3389/fbuil.2022.899332-B62030.svg)](https://www.frontiersin.org/articles/10.3389/fbuil.2022.899332)


[//]: # ([![GitHub issues]&#40;https://img.shields.io/github/issues/tudelft3d/3dfier&#41;]&#40;https://github.com/tudelft3d/3dfier/issues&#41;)

# City4CFD

City4CFD--*City for CFD*--is a tool that aims to automatically reconstruct 3D city geometries tailored for microscale urban flow simulations.

It can create automatically a terrain from a point cloud and imprint different surfaces (e.g. green areas, water, roads).

It enables us to reconstruct buildings from different sources and their combination, such as:
  - Reconstruction with the combination of 2D polygons and a point cloud,
  - Extrusion of footprints containing height or floor number attributes,
  - The import of existing building models.

The resulting geometry is watertight -- buildings and surfaces are seamlessly integrated into a terrain.

It can automatically or manually define the zone of influence and domain boundaries.

If you happen to use it, feedback is very much appreciated.

City4CFD is developed by the [3D Geoinformation Research Group](https://3d.bk.tudelft.nl/) at the Delft University of Technology.

## Data formats
**Point clouds** can be imported in LAS/LAZ, XYZ, or PLY format. We ask separately for ground and building points. While some datasets contain building-ground classification, some do not. In case your LAS/LAZ file has buildings/ground classified, you can use [point cloud preparation script](https://github.com/tudelft3d/City4CFD/blob/main/tools/prepare_point_cloud.sh) to create separate files. If buildings and terrain are under the same class, or vegetation is not filtered out, we suggest you use [CloudCompare](https://www.danielgm.net/cc/) to prepare points.

**2D data** (polygons) are imported in GeoJSON format. For all pre-processing related to polygons, including conversion to GeoJSON, you can use [QGIS](https://qgis.org/en/site/).

**Geometry import** supports the following formats: OBJ, STL, PLY, OFF, VTP, and CityJSON.

**Output** is in the following formats: OBJ, STL, and CityJSON. The ID of each polygon is preserved, and there is a 1-to-1 mapping between the input and the output.

## Installation
You can directly compile City4CFD on your system using cmake, run it through a Docker container, or install using Homebrew in case of macOS.

### Build from source
The following libraries are required to build the project:
- [CGAL](https://www.cgal.org/) version 5
- Boost >= 1.66

Both dependencies are generally available in Linux distributions (Debian/Ubuntu/Mint) as *libcgal-dev* and *libboost-dev*, and in macOS with Homebrew as *cgal* and *boost*.
The project uses CMake to generate makefiles, so make sure it is also installed.

To build City4CFD, do the following:
```
mkdir build && cd build
cmake ..
make
./city4cfd
```
You can speed up compilation by typing *make -j $numcores* where *$numcores* is the number of threads you can spare for compilation.

### Docker
We offer built [Docker](https://www.docker.com/) images for every release, available at the [Docker Hub](https://hub.docker.com/r/tudelft3d/city4cfd). Running the docker script for the first time will pull the docker image from the Docker Hub repository.

### macOS
Mac users can install City4CFD through Homebrew:

```
brew tap tudelft3d/software
brew install city4cfd
```

## Getting started

The folder *examples* contains example datasets you can run for your first reconstruction. You can run your first reconstruction from the `/examples/TUD_Campus` folder by typing:
```
mkdir results
../../build/city4cfd config_bpg.json --output_dir results
```
in case of building from a source.

To run through a Docker container, you can use one of the scripts in ```docker/run/```. The script with the extension ```.sh``` can be used in Linux and macOS, the one with the extension ```.ps1``` in Windows Powershell, and the last one with ```.bat``` in Windows Command Prompt. You have to run  a script (you can copy it beforehand) from the root directory of the project (e.g. ```examples/TUD_Campus```), and the arguments are the same as for the compiled executable, e.g.: 

```
../../docker/run/city4cfd_run.sh config_bpg.json --output_dir results
```

The script pulls the ```latest``` release from the Docker Hub. For a specific release, replace ```latest``` in the script with the released version tag, e.g. ```0.1.0```. In Linux systems, you will probably have to run the command as a sudo unless you create a 'docker' group and add users to it.

More information on the project can be found in the documentation.

## Documentation
The [wiki section](https://github.com/tudelft3d/City4CFD/wiki) of this project has details on reconstruction setup and also contains information and suggestions on data preparation.

## Citation
If you use City4CFD in a scientific context, please cite the following paper:

Pađen, Ivan, García-Sánchez, Clara and Ledoux, Hugo (2022). Towards Automatic Reconstruction of 3D City Models Tailored for Urban Flow Simulations. *Frontiers in Built Environment*, 8, 2022 [[DOI](https://www.frontiersin.org/articles/10.3389/fbuil.2022.899332)][[BibTeX](https://github.com/tudelft3d/City4CFD/blob/master/CITATION.bib)]

## Acknowledgements
We would like to acknowdledge the authors of supporting libraries we use in this project:
[CGAL](https://github.com/CGAL/cgal), [nlohmann/json](https://github.com/nlohmann/json), [valijson](https://github.com/tristanpenman/valijson), [LAStools](https://github.com/LAStools)

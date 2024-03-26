#include <fstream>
#include <vector>
using namespace std;
using size_type = unsigned;
struct Body {
    size_type NNcoords;
    size_type Ntriangles;
    vector<vector<double>> Ncoords;
    vector<vector<size_type>> Elemes;
    void readFile(fstream& file) {
        int number_points{};
        file >> number_points;
        NNcoords = number_points;
        Ncoords.resize(number_points);
        for (auto& i : Ncoords) {
            i.resize(3);
        }
        // Ncoords
        for (int point_index{}; point_index < number_points; point_index++) {
            for (int coords_index{}; coords_index < 3; coords_index++) {
                file >> Ncoords.at(point_index).at(coords_index);
                // Ncoords[point_index].push_back(temp);
            }
        }
        int number_triangles{};
        file >> number_triangles;
        Ntriangles = number_triangles;
        Elemes.resize(number_triangles);
        for (auto& i : Elemes) {
            i.resize(3);
        }
        for (int point_index{}; point_index < number_triangles; point_index++) {
            for (int coords_index{}; coords_index < 3; coords_index++) {
                file >> Elemes.at(point_index).at(coords_index);
            }
        }
    }
    Body() {}
    Body(Body& bd) {
        Ncoords = bd.Ncoords;
        Elemes = bd.Elemes;
    }
    Body(fstream& file) { readFile(file); }
    ~Body() {}
};
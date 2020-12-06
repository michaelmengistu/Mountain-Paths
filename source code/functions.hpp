//
//  functions.hpp
//  Mountain Paths
//
//  Created by Michael Mengistu on 3/6/18.
//  Copyright © 2018 Michael Mengistu. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <vector>



using namespace std;

int startRow(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int& start_row, int& newColumn, int& beginColumn, int& nextColumn, int& distance);

int endRow(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int& start_row, int& newColumn, int& beginColumn, int& nextColumn, int& distance);

int middleRows(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int& start_row, int& newColumn, int& beginColumn, int& nextColumn, int& endColumn, int& distance);

int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int start_row);

int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int start_row, int start_col);

#endif /* functions_hpp */

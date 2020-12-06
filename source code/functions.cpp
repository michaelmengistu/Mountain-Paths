  //
//  functions.cpp
//  Mountain Paths
//
//  Created by Michael Mengistu on 3/6/18.
//  Copyright © 2018 Michael Mengistu. All rights reserved.
//

#include "functions.hpp"
#include <cmath>
#include <cctype>
#include <iostream>

using namespace std;

// for the begining row
int startRow(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int& start_row, int& newColumn, int& beginColumn, int& nextColumn, int& distance){
    while(start_row == 0){
        beginColumn = abs(heightMap[start_row][0+newColumn] - heightMap[start_row][1+newColumn]);
        nextColumn = abs(heightMap[start_row][0+newColumn] - heightMap[1+start_row][1+newColumn]);
        if(beginColumn + distance <= nextColumn + distance){
            r[start_row][1+newColumn] = color_r;
            g[start_row][1+newColumn] = color_g;
            b[start_row][1+newColumn] = color_b;
            distance = beginColumn + distance;
            ++newColumn;
            if (newColumn == heightMap[start_row].size()-1) {
                break;
            }
        }
        else{
            r[1+start_row][1+newColumn] = color_r;
            g[1+start_row][1+newColumn] = color_g;
            b[1+start_row][1+newColumn] = color_b;
            start_row = start_row + 1;
            distance = nextColumn + distance;
            ++newColumn;
            break;
        }
    }
    return distance;
}

//at the last row
int endRow(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int& start_row, int& newColumn, int& beginColumn, int& nextColumn, int& distance){
    
    
    while(start_row == heightMap.size()-1){
        beginColumn = abs(heightMap[start_row][0+newColumn] - heightMap[start_row][1+newColumn]);
        nextColumn = abs(heightMap[start_row][0+newColumn] - heightMap[start_row-1][1+newColumn]);
        if(beginColumn + distance <= nextColumn + distance){
            r[start_row][1+newColumn] = color_r;
            g[start_row][1+newColumn] = color_g;
            b[start_row][1+newColumn] = color_b;
            distance += beginColumn;
            ++newColumn;
            if (newColumn == heightMap[start_row].size()-1) {
                break;
            }
        }
        else{
            r[start_row-1][1+newColumn] = color_r;
            g[start_row-1][1+newColumn] = color_g;
            b[start_row-1][1+newColumn] = color_b;
            
            distance += nextColumn;
            --start_row;
            ++newColumn;
            
        }
    }
    return distance;
}

// all the middle Rows
int middleRows(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int& start_row, int& newColumn, int& beginColumn, int& nextColumn, int& endColumn, int& distance){
    
    while(newColumn != (heightMap[start_row].size()-1) ) {
        beginColumn = abs(heightMap[start_row][0+newColumn] - heightMap[start_row-1][1+newColumn]);
        nextColumn = abs(heightMap[start_row][0+newColumn] - heightMap[start_row][1+newColumn]) ;
        endColumn = abs(heightMap[start_row][0+newColumn] - heightMap[start_row+1][1+newColumn]);
        
     
        if(beginColumn + distance < nextColumn + distance && beginColumn + distance < endColumn + distance){
            r[start_row-1][1+newColumn] = color_r;
            g[start_row-1][1+newColumn] = color_g;
            b[start_row-1][1+newColumn] = color_b;
            distance += beginColumn;
            --start_row;
            ++newColumn;
            
            if(start_row == 0){
                distance = startRow(heightMap, r, g, b, color_r, color_g, color_b, start_row, newColumn, beginColumn, nextColumn, distance);
            }
        }
        else if (endColumn + distance <= beginColumn + distance && endColumn + distance < nextColumn + distance){
            r[start_row+1][1+newColumn] = color_r;
            g[start_row+1][1+newColumn] = color_g;
            b[start_row+1][1+newColumn] = color_b;
            distance += endColumn;
            ++start_row;
            ++newColumn;
             cout << "goes to South" <<endl;
            if(start_row == heightMap.size()-1){
                distance = endRow(heightMap, r, g, b, color_r, color_g, color_b, start_row, newColumn, beginColumn, nextColumn, distance);
            }
        }
        else{
            r[start_row][1+newColumn] = color_r;
            g[start_row][1+newColumn] = color_g;
            b[start_row][1+newColumn] = color_b;
            distance += nextColumn;
            ++newColumn;
             cout << "goes to East" <<endl;
        }
    }
    return distance;
}

int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int start_row){
    int distance = 0;
    int beginColumn = 0;
    int nextColumn = 0;
    int endColumn = 0;
    int newColumn = 0;
    
    r[start_row][0] = color_r;
    g[start_row][0] = color_g;
    b[start_row][0] = color_b;
    while(newColumn != heightMap[start_row].size()-1){
        if(start_row == 0){
            distance = startRow(heightMap, r, g, b, color_r, color_g, color_b, start_row, newColumn, beginColumn, nextColumn, distance);
        }
        else if(start_row < heightMap.size()-1 ){
            distance = middleRows(heightMap, r, g, b, color_r, color_g, color_b, start_row, newColumn, beginColumn, nextColumn, endColumn, distance);
        }
        else{
            distance = endRow(heightMap, r, g, b, color_r, color_g, color_b, start_row, newColumn, beginColumn, nextColumn, distance);
        }
    }
    
    return distance;
}

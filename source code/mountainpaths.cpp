
#include <iostream>
#include <fstream>
#include <string>
#include "functions.hpp"

using namespace std;
int main(){
    string fileName;
    int row = 0;
    int col = 0;
    int ec_row;
    int ec_column;
    cout << "Enter the rows:";
    cin>> row;
    cout <<"Enter the columns:";
    cin >> col;
    cout <<"enter loction of data:";
    cin >> fileName;
    
    
    
    ifstream datafile {fileName};
    
    if (!datafile.is_open()) {
        cout << "Error: Can't open the file named " << fileName <<"." <<endl;
        return 1;
    }
    
    
    
    //takes data from file and makes into 2d vector
    vector<vector<int>> pictureData(row,(vector<int>(col,0)));
    for (int i = 0; i < pictureData.size(); ++i) {
        for (int j = 0; j < pictureData.at(i).size(); ++j){
            if(!datafile.eof()){
                int data;
                datafile >> data;
                pictureData.at(i).at(j) = data;
            }
        }
    }
           
            
    //finds the min value and max value
    int minValue = pictureData[0][0];
    int maxValue = pictureData[0][0];
    for (int i = 0; i <pictureData.size(); ++i) {
        for (int j = 0; j < pictureData[i].size(); ++j) {
            if (minValue > pictureData[i][j]) {
                minValue = pictureData[i][j];
            }
            if (maxValue < pictureData[i][j] ) {
                maxValue = pictureData[i][j];
            }
        }
    }

    //R,G,B color made into 2d vector
    vector<vector<int>> R(row,(vector<int>(col,0)));
    vector<vector<int>> G(row,(vector<int>(col,0)));
    vector<vector<int>> B(row,(vector<int>(col,0)));
                                    
    for(int i=0;i<pictureData.size();++i){
        for(int j=0;j<pictureData[i].size();++j){
            int color = 0;
            color = (((double)pictureData.at(i).at(j) - (double)minValue)/((double)maxValue-(double)minValue))*255;
            R.at(i).at(j) = color;
            G.at(i).at(j) = color;
            B.at(i).at(j) = color;
        }
}
    //finds all the paths in the picture
    int distance = 0;
    int shortestRow =0;
    int shortestDistance = 2147483647; //set it to the max amount an intger can be
    for(int i=0;i<pictureData.size();++i){
        distance = colorPath(pictureData, R, G, B, 252, 25, 63, i);
        if (shortestDistance > distance  ){ //finds shortest row
            shortestDistance = distance;
            shortestRow = i;
        }
    }
    
    distance = colorPath(pictureData, R, G, B, 31, 253, 13, shortestRow);
   
    
    if(cin >> ec_row) {  //ec for extra credit!
        //call function to paint paths for point
        distance = colorPath(pictureData, R, G, B, 19, 254, 253, ec_row);
    }
    
    
    //PPM file
    string outFileName = fileName+".ppm";
    ofstream PPM {outFileName};
    
    if (!PPM.is_open()) {
        cout << "Error: Can't open the file named " << outFileName <<"." <<endl;
        return 1;
    }
    
    PPM << "P3" << endl;
    PPM << col << " " << row << endl;
    PPM << 255 << endl;
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            PPM <<  R.at(i).at(j) << " " <<  G.at(i).at(j) << " " <<  B.at(i).at(j)<< " ";
            if (j == col-1){
                PPM << endl;
            }
        }
    }
    
    
    return 0;
}

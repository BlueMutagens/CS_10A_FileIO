//
//  main.cpp
//  Homework15
//
//  Created by Sean Belingheri on 12/13/22.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    ifstream inputFile;
    string file, temp;
    int rows = 0, columns = 0;

    
    cout<<"Enter file name: ";
    cin>>file;
    
    inputFile.open(file);
    cout<<"Now reading "<<file<<"..."<<endl;
 
    
    while(getline(inputFile, temp))
    {
        rows++;
    }
    
    inputFile.close();
    inputFile.open(file);
    
    while(inputFile >> temp)
    {
        columns++;
    }
    inputFile.close();
    
    columns /= rows;
    
    cout<<"Matrix size: "<<rows<<"x"<<columns<<endl;
    return 0;
    
}

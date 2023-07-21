//
//  dataFormat.cpp
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

void sumStats(int arrproto[], int sizeproto, double * mean, double * range, double * median);

int main()
{
    ifstream inputFile;
    string file, temp, outfile = "dataOut.txt";
    int rows = 0, columns = 0, input;
    double mean = 0, range = 0, median;
    
    int**matrix=NULL;
    

    cout<<"Enter file name: ";
    cin>>file;
    
    inputFile.open(file);
    cout<<"Now reading "<<file<<"..."<<endl;
    
    if(inputFile.is_open())
        cout << "File is open!" << endl;
    else
        cout << "Try again" << endl;

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
    //Rows and Columns have been calculated
    
    matrix=new int*[rows];
    for(int k=0; k<rows; k++)
        matrix[k] = new int[columns];
    
    inputFile.open(file);
    
    for(int k=0; k < rows; k++)
        for(int g = 0; g< columns; g++)
        {
            inputFile >> input;
            matrix[k][g] = input;
        }
    inputFile.close();
    
    
    //2d matrix created
    
    cout<<"Writing results to "<<outfile<<endl;
    
    
    for(int s = 0; s<rows; s++)
        for(int d = 0; d<columns-1; d++)
        {
            if(matrix[s][d] > matrix[s][d+1])
            {
                matrix[s][d+1] += matrix[s][d];
                matrix[s][d] = matrix[s][d+1] - matrix[s][d];
                matrix[s][d+1] -= matrix[s][d];
                d = -1;
            }
        }
 //Matrix is now sorted least to greatest by row only
    
    
    int prec = 2, mean_rangew = 7, medianw = 8, roww = 2; // output modifiers
    int*rowbyrow=NULL;
    rowbyrow=new int[columns];
    
    ofstream outputFile;
    outputFile.open(outfile);
    
    outputFile<<left<<setprecision(prec)<<fixed;
    outputFile<<setw(mean_rangew-1)<<""<<"|"<<setw(mean_rangew)<<"Mean"<<"|"<<setw(medianw)<<"Median"<<"|"<<setw(mean_rangew)<<"Range"<<"|"<<endl;
    outputFile << "------+-------+--------+-------+"<<endl;
    //Top level done
    
    for(int i = 0; i < rows; i++)
    {
        for(int z = 0; z < columns; z++)
            rowbyrow[z] = matrix[i][z]; //creates an array for each row of the 2d matrix, since passing a 2d matrix into a function is kinda confusing
        sumStats(rowbyrow, columns, &mean, &range, &median);
        outputFile<<"Row "<<setw(roww)<<i+1<<"|"<<setw(mean_rangew)<<mean<<"|"<<setw(medianw)<<median<<"|"<<setw(mean_rangew)<<range<<"|"<<endl;
    }
    
    
    //outputFile<<"Row "<<setw(roww)<<1<<"|"<<setw(mean_rangew)<<5.1<<"|"<<setw(medianw)<<10.0<<"|"<<setw(mean_rangew)<<15.8<<"|"<<endl;
    
    
    
    outputFile.close();
    cout<<"Done"<<endl;
    
    return 0;
}


void sumStats(int arrproto[], int sizeproto, double * mean, double * range, double * median)
{
    *mean = 0;
    for(int g = 0; g < sizeproto; g++)
        *mean += arrproto[g];
    *mean /= sizeproto;
    
    double min=arrproto[0], max=0;
    
    for(int g = 0; g < sizeproto; g++)
    {
        if(arrproto[g] < min)
            min = arrproto[g];
        if(arrproto[g] > max)
            max = arrproto[g];
    }
    *range = max - min;
    
    if(sizeproto % 2 == 0)
    {
        *median = (arrproto[sizeproto/2] + arrproto[(sizeproto/2) - 1])/2;
    }
    else
    {
        *median = arrproto[(sizeproto/2)];
    }
}

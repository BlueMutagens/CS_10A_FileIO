//
//  test.cpp
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
    cout<<left<<setprecision(2)<<fixed;
    cout<<setw(6)<<""<<"|"<<setw(7)<<"Mean"<<"|"<<setw(8)<<"Median"<<"|"<<setw(7)<<"Mode"<<"|"<<endl;
    cout<<<<endl;
    cout<<"Row "<<setw(2)<<1<<"|"<<setw(7)<<5.1<<"|"<<setw(8)<<10.0<<"|"<<setw(7)<<15.8<<"|"<<endl;
    return 0;
}

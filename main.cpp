#include <iostream>
#include <fstream>
#include <vector>

#include "MyMatrix.h"

using namespace std;

int main()
{  

    ifstream input;
    input.open("../MacierzOdwrotna/matrix.txt", ios::in);

    if(input.good() != true) {
        cout << "Can't find a file!" << endl;
        return 0;
    }

    // file opened
    int N;

    input >> N; // read first number (int) it will be dimension of matrix N  (matrix is N*N)

    vector<double> row;
    double value;
    vector<vector<double> > m;

    // read values from file
    for(int i = 0; i < N; i++) {
        row.clear();
        for(int j = 0; j < N; j++) {
            input >> value;
            row.push_back(value);
        }
        m.push_back(row);
    }

    input.close();


    vector<vector<double> > result;
    result = MyMatrix::inverse(m);

    ofstream output;
    output.open("../MacierzOdwrotna/matrix_output.txt", ios::out);
    output << result.size() << "\n";

    // display matrix and put into file
    for(int i = 0; i < (int)result.size(); i++) {
        for(int j = 0; j < (int)result.size(); j++) {
            cout << result[i][j] << "\t\t";
            output << result[i][j] << "\t";
        }
        cout << endl;
        output << "\n";
    }


    output.close();

    return 0;

}


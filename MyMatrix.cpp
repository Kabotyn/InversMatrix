#include <vector>
#include <cmath>

#include "MyMatrix.h"

using namespace std;

/******************************************************/
vector<vector<double> > operator/(vector<vector<double> > m, double d) {

    for( int i = 0; i < (int)m.size(); i++) {
        for(int j = 0; j < (int)m.size(); j++) {
            m[i][j] = m[i][j] / d;
        }
    }

    return m;
}
/******************************************************/
vector<vector<double> > MyMatrix::minor(int deleteRow, int deleteCol, vector<vector<double> > m) {

    vector<vector<double> > result;
    vector<double> row;

    for( int i = 0; i < (int)m.size(); i++) {
        if(i == deleteRow) continue;

        row.clear();
        for(int j = 0; j < (int)m.size(); j++) {
            if(j == deleteCol) continue;

            row.push_back(m[i][j]);
        }
        result.push_back(row);
    }

    return result;

}
/******************************************************/
double MyMatrix::det(vector<vector<double> > m) {
    if (m.size() == 1)
        return m[0][0];

    double sum = 0;
    int j = 0;

    for(int i = 0; i < (int)m.size(); i++) {
        sum += pow((double)(-1), (double)(i+j+1)) * m[i][j] * det(minor(i, j, m));
    }

    return sum;

}
/******************************************************/
vector<vector<double> > MyMatrix::cofactor(vector<vector<double> > m) {

    vector<vector<double> > result;
    vector<double> row;

    double value;

    for( int i = 0; i < (int)m.size(); i++) {
        row.clear();
        for(int j = 0; j < (int)m.size(); j++) {
            value = pow((double)(-1), (double)(i+1+j)) * det(minor(i, j, m));
            row.push_back(value);
        }
        result.push_back(row);
    }

    return result;

}
/******************************************************/
vector<vector<double> > MyMatrix::transpose(vector<vector<double> > m) {

    vector<vector<double> > result;
    result = m;

    for( int i = 0; i < (int)result.size(); i++) {
        for(int j = 0; j < (int)result.size(); j++) {
            result[j][i] = m[i][j];
        }
    }

    return result;

}
/******************************************************/
vector<vector<double> > MyMatrix::adjugate(vector<vector<double> > m) {

    vector<vector<double> > result;

    result = cofactor(m);
    result = transpose(result);

    return result;
}
/******************************************************/
vector<vector<double> > MyMatrix::inverse(vector<vector<double> > m) {

    vector<vector<double> > result;
    double det_m = det(m);
    result = adjugate(m);

    result = result / det_m;

    return result;

}
/******************************************************/

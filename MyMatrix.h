#include <vector>
#include <cmath>

using namespace std;

class MyMatrix {
	
public:
	

    // cout minor matrix
    static vector<vector<double> > minor(int deleteRow, int deleteCol, vector<vector<double> > m);
	
    // count determinant
    static double det(vector<vector<double> > m);
	
    // count cofactor matrix
    static vector<vector<double> > cofactor(vector<vector<double> > m);
	
    // count transpose matrix
    static vector<vector<double> > transpose(vector<vector<double> > m);
	
    // count adjugate matrix
    static vector<vector<double> > adjugate(vector<vector<double> > m);
	
    // count inverse matrix
    static vector<vector<double> > inverse(vector<vector<double> > m);

	
};

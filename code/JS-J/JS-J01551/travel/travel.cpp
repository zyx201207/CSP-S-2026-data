#include<bits/stdc++.h>
using namespace std;

int main()
{
    auto f_in = ifstream("./travel.in", ios::in);
    auto f_out = ofstream("./travel.out", ios::out);
    
    string R_c, R_z;
    f_in >> R_c >> R_z;

    string X_c, X_z;
    f_in >> X_c >> X_z;
    
    
    
    if (R_c == X_c)
    {
        f_out << "1";
    }
    else
    {
        f_out << "0000";
        // fstream(f_out);
        return 0;
    }

    if ((R_z[0] == X_z[0]) && (R_z[1] == X_z[1]))
    {
        f_out << "1";
    }
    else
    {
        f_out << "000";
        // fstream(f_out);
        return 0;
    }

    if ((X_z[2] <= 'C' && R_z[2] <= 'C') || (X_z[2] > 'C' && R_z[2] > 'C'))
    {
        f_out << "1";
    }
    else
    {
        f_out << "00";
        // fstream(f_out);
        return 0;
    }

    if (X_z[2] + 1 == R_z[2] || X_z[2] - 1 == R_z[2])
    {
        f_out << "1";
    }
    else
    {
        f_out << "0";
        // fstream(f_out);
        return 0;
    }
    // fstream(f_out);
    return 0;
}
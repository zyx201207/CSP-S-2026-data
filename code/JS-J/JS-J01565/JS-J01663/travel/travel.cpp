
#include <bits/stdc++.h>
using namespace std;

int main() {



    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a, b, c, d;
    cin >> a >> b >> c >> d;



    int b_s, d_s;
    b_s = (b[0] - '0')*10 + b[1] - '0';
    d_s = (d[0] - '0')*10 + d[1] - '0';

    char r_b = b[2];
    char x_b = d[2];


    if (a == c) {
        cout << "1";
        if (b_s == d_s){
            cout << "1";
            if (('A' <= r_b && r_b <= 'C' && 'A' <= x_b && x_b <= 'C')) cout << "1";
            else if ((r_b == 'F' && x_b == 'D') || (x_b == 'F' && r_b == 'D')) cout << "1";
            else cout << "0";
        } else {
            cout << "00";
        }

        if ((r_b == 'C' && x_b == 'D') || (r_b == 'D' && x_b == 'C')) {
            cout << "0";
            return 0;
        }

        if ((abs(b_s - d_s) == 1 && abs(int(r_b-x_b)) == 0) || (abs(b_s - d_s) == 0 && abs(int(r_b-x_b)) == 1)) cout << 1;
        else cout << "0";

    } else {
        cout << "0000";
    }

    return 0;
}



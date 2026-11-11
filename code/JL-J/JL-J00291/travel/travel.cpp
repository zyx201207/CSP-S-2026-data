#include <bits/stdc++.h>
using namespace std;

string n, x, m, y;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> n >> x >> m >> y;

    if(n == m) {
        cout << "1";

        if(x[0] + x[1] == y[0] + y[1]) {
            cout << "1";

            if( ((x[2] == 'A' || x[2] == 'B' || x[2] == 'C')&&(y[2] == 'A' || y[2] == 'B' || y[2] == 'C')) || ((x[2] == 'E' || x[2] == 'F')&&(y[2] == 'E' || y[2] == 'F') ) ) {
                cout << "1";

                if( ((x[2] == 'A' && y[2] == 'B') || (x[2] == 'B' && y[2] == 'C') || (x[2] == 'E' && y[2] == 'F')) || ((x[2] == 'B' && y[2] == 'A') || (x[2] == 'C' && y[2] == 'B') || (x[2] == 'F' && y[2] == 'E')) ) {
                    cout << "1";
                }
                else {
                    cout << "0";
                }
            }
            else {
                cout << "00";
            }
        }
        else {
            cout << "000";
        }
    }
    else {
        cout << "0000";
    }

    return 0;
}

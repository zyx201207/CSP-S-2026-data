#include <bits/stdc++.h>
using namespace std;

int r_train;
string r_seat;
int x_train;
string x_seat;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> r_train >> r_seat >> x_train >> x_seat;
    if (r_train != x_train) {
        cout << "0000\n";
    } else {
        cout << "1";
        if (r_seat[0] == x_seat[0] && r_seat[1] == x_seat[1]) {
            cout << "1";
            
            char r = r_seat[2], x = x_seat[2];
            // if (x == 'C' && r == 'D' || x == 'D' && r == 'C') {
            //     cout << "00\n";
            // }
            if ((r == 'A' || r == 'B' || r == 'C') && (x == 'A' || x == 'B' || x == 'C') || ((r == 'D' || r == 'F') && (x == 'D' || x == 'F'))) {
                cout << "1";
                if (x == 'A' && r == 'B' || x == 'B' && r == 'A' || x == 'B' && r == 'C' || x == 'C' && r == 'B' || x == 'D' && r == 'F' && x == 'F' && r == 'D') {
                    cout << "1\n";
                }
                else {
                    cout << "0\n";
                }
            } else {
                cout << "00\n";
            }
        } else {
            cout << "000\n";
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a1, a2, c1, c2;
    cin >> a1 >> a2 >> c1 >> c2;
    int a = (int)(a2[0] - '0') * 10 + (int)(a2[1] - '0'), c = (int)(c2[0] - '0') * 10 + (int)(c2[1] - '0');

    if (a1 == c1) {
        if (a == c) {
            if (a2[2] <= 'C' && c2[2] <= 'C') {
                if (abs(a2[2] - c2[2]) == 1) {
                    cout << "1111";
                }
                else cout << "1110";
            }
            else if (a2[2] >= 'D' && c2[2] >= 'D') {
                cout << "1111";
            }
            else cout << "1100";
        }
        else cout << "1000";
    }
    else cout << "0000";
    return 0;
}

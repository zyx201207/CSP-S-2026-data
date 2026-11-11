#include <bits/stdc++.h>
using namespace std;
int r, x;
string r1, x1;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> r1 >> x >> x1;
    bool f1 = (r == x);
    bool f2 = (f1 && (r1[0] == x1[0] && r1[1] == x1[1]));
    bool f3 = (f2 && (r1[2] == 'A' || r1[2] == 'B' || r1[2] == 'C') && (x1[2] == 'A' || x1[2] == 'B' || x1[2] == 'C') || (r1[2] == 'D' || r1[2] == 'F') && (x1[2] == 'D' || x1[2] == 'F'));
    bool f4 = (f3 && min(r1[2], x1[2]) + 1 == max(r1[2], x1[2]));
    cout << f1 << f2 << f3 << f4;

    return 0;
}

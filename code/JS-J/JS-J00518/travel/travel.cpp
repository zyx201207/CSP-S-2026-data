#include <bits/stdc++.h>

using namespace std;

using lld = long long;

string c1, s1, c2, s2;

bool check1() {
    return c1 == c2;
}

bool check2() {
    int lin1 = (s1[0] - '0')*10 + (s1[1] - '0');
    int lin2 = (s2[0] - '0')*10 + (s2[1] - '0');
    int row1 = s1[2] - 'A';
    int row2 = s2[2] - 'A';

    if (!check1()) return false;

    return lin1 == lin2;
}

bool check3() {
    int lin1 = (s1[0] - '0')*10 + (s1[1] - '0');
    int lin2 = (s2[0] - '0')*10 + (s2[1] - '0');
    int row1 = s1[2] - 'A';
    int row2 = s2[2] - 'A';

    if (!check2()) return false;

    if (row1 <= 2 && row2 <= 2) return true;
    else if (row1 > 2 && row1 > 2) return false;
    else return false;
}

bool check4() {
    int lin1 = (s1[0] - '0')*10 + (s1[1] - '0');
    int lin2 = (s2[0] - '0')*10 + (s2[1] - '0');
    int row1 = s1[2] - 'A';
    int row2 = s2[2] - 'A';

    if (!check3()) return false;

    return abs(row1 - row2) == 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;

    
    cout << check1() << check2() << check3() << check4() << endl;

    return 0;
}
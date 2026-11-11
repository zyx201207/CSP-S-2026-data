#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

    string s1, c1, s2, c2;
    cin >> s1 >> c1 >> s2 >> c2;


    bool flag1, flag2, flag3, flag4;
    flag1 = s1 == s2;

    flag2 = (flag1) && c1.substr(0, 2) == c2.substr(0, 2);

    flag3 = (flag1 && flag2) && (c1[2] <= 'C' && c2[2] <= 'C') || (c1[2] > 'C' && c2[2] > 'C');

    flag4 = (flag1 && flag2 && flag3) && (abs(c1[2] - c2[2]) == 1 || (c1[2] == 'F' && c2[2] == 'D') || (c1[2] == 'D' && c2[2] == 'F'));

    cout << flag1 <<flag2 << flag3 << flag4;

    return 0;
}
    

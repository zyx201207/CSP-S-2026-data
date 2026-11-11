#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c1, s1, c2, s2, flag;
    char ch1, ch2;
    cin >> c1 >> s1 >> ch1 >> c2 >> s2 >> ch2;
    cout << (flag = c1 == c2);
    cout << (flag &= s1 == s2);
    cout << (flag &= (ch1 <= 'C' && ch2 <= 'C') || (ch1 >= 'D' && ch2 >= 'D'));
    cout << (flag &= ch1 + ch2 != 'A' + 'C');
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c1, c2, t1, t2;
char s1, s2;
map<char, ll> a;
int main() {
    a['A'] = a['B'] = a['C'] = 1;
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> t1 >> s1 >> c2 >> t2 >> s2;
    if (c1 == c2) {
        cout << "1";
    } else {
        cout << "0000";
        return 0;
    }
    if (t1 == t2) {
        cout << "1";
    } else {
        cout << "000";
        return 0;
    }
    if (a[s1] == a[s2]) {
        cout << "1";
    } else {
        cout << "00";
        return 0;
    }
    if (s1 - s2 == 1 || s1 - s2 == -1) {
        cout << "1";
    } else {
        cout << "0";
    }
    return 0;
}

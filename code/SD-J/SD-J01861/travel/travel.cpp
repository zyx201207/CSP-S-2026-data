#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {
        cout << "0000";
        return 0;
    }
    if (s1.substr(0, 2) != s2.substr(0, 2)) {
        cout << "1000";
        return 0;
    }
    if ((s1[2] <= 'C' && s2[2] >= 'D') || (s1[2] >= 'D' && s2[2] <= 'C')) {
        cout << "1100";
        return 0;
    }
    if ((s1[2] + 1 != s2[2]) && (s1[2] != s2[2] + 1)) {
        cout << "1110";
        return 0;
    }
    cout << "1111";
    return 0;
}

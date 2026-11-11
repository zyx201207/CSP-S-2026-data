#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string c_1, s_1, c_2, s_2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("travel1.in", "r", stdin);
    freopen("travel1.out", "w", stdout);

    cin >> c_1 >> s_1 >> c_2 >> s_2;

    if (c_1 == c_2) {
        cout << "1";
    } else {
        cout << "0000\n";
        return 0;
    }

    if (s_1.substr(0,2) == s_2.substr(0,2)) {
        cout << "1";
    } else {
        cout << "000\n";
        return 0;
    }
    
    int pos_1 = s_1[2] - 'A';
    int pos_2 = s_2[2] - 'A';
    if (pos_1 > pos_2)  swap(pos_1, pos_2);

    if (pos_2 <= 2 || pos_1 >= 3) {
        cout << "1";
    } else {
        cout << "00\n";
        return 0;
    }

    if ((pos_1 == 0 && pos_2 == 1) || (pos_1 == 1 && pos_2 == 2) || (pos_1 == 3 && pos_2 == 5)) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }

    return 0;
}
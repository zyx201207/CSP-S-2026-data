#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << "1";
        string ct1, ct2;
        for (int i = 0; i <= 1; i++) {
            if (s1[i] == s2[i] && i == 1) {
                cout << "1";
                if ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'E' && s2[2] >= 'D' && s2[2] <= 'E')) {
                    cout << "1";
                    if ((s1[2] == 'A' && s2[2] == 'B') || (s2[2] == 'A' && s1[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s2[2] == 'B' && s1[2] == 'C') || (s1[2] == 'D' && s2[2] == 'E') || (s2[2] == 'D' && s1[2] == 'E')) {
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
            if (s1[i] != s2[i]) {
                cout << "000";
                return 0;
            }
        }
    }
    else {
        cout << "0000";
    }
    return 0;
}
//luogu:static_sumer
//hua feng xia yun,luo shui tian yi.
//Draco Malfoy & Harry Potter 99
//9:16
/*
zou ba jiu suan wo men wu fa rang da yv ting xia
hai you wo pei ni zai yv li fang si ben pao a
*/

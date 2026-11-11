#include <bits/stdc++.h>

using namespace std;

using LL = long long;

int side(char c)
{
    if (c == 'A' || c == 'B' || c == 'C') {
        return 1;
    } else {
        return 2;
    }
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    string c1, s1, c2, s2;

    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << "1";
        if (s1.substr(0, 2) == s2.substr(0, 2)) {
            cout << "1";
            if (side(s1[2]) == side(s2[2])) {
                cout << "1";
                char t1 = s1[2], t2 = s2[2];
                if (t1 > t2) {
                    swap(t1, t2);
                }
                if ((t1 == 'A' && t2 == 'B') || (t1 == 'B' && t2 == 'C') || (t1 == 'D' && t2 == 'F')) {
                    cout << "1";
                } else {
                    cout << "0";
                }
            } else {
                cout << "00";
            }
        } else {
            cout << "000" << endl;
        }
    } else {
        cout << "0000" << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

#define int long long
#define PII pair <int, int>

using namespace std;

struct node{
    int it1, it2, it3;
};

void solve() {
    string Ac, Ap, Bc, Bp;
    cin >> Ac >> Ap >> Bc >> Bp;
    node A, B;
    A.it1 = 0, A.it2 = 0, A.it3 = 0;
    B.it1 = 0, B.it2 = 0, B.it3 = 0;
    for (auto it : Ac)
        A.it1 = (A.it1 * 10) + (it - '0');
    for (auto it : Bc)
        B.it1 = (B.it1 * 10) + (it - '0');
    for (int i = 0; i < 2; i++)
        A.it2 = (A.it2 * 10) + (Ap[i] - '0');
    for (int i = 0; i < 2; i++)
        B.it2 = (B.it2 * 10) + (Bp[i] - '0');
    A.it3 = Ap[2] - 'A' + 1;
    B.it3 = Bp[2] - 'A' + 1;

//    cout << A.it1 << ' ' << A.it2 << ' ' << A.it3 << '\n'
//         << B.it1 << ' ' << B.it2 << ' ' << B.it3 << '\n';

    if (A.it1 == B.it1) {
        cout << "1";
        if (A.it2 == B.it2) {
            cout << "1";
            if ( (A.it3 <= 3 && B.it3 <= 3) || (A.it3 > 3 && B.it3 > 3)) {
                cout << "1";
                if (abs (A.it3 - B.it3) == 1)
                    cout << "1";
                else
                    cout << "0";
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
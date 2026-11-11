#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    int c1, s1, c2, s2;
    char t1, t2;
    cin >> c1 >> s1 >> t1 >> c2 >> s2 >> t2;

    if (c1 == c2) cout << "1";
    else cout << "0";

    if (c1 == c2 && s1 == s2) cout << "1";
    else cout << "0";

    if (c1 == c2 && s1 == s2 &&
    ((t1 >= 'A' && t1 <= 'C' && t2 >= 'A' && t2 <= 'C') || (t1 >= 'D' && t1 <= 'F' && t2 >= 'D' && t2 <= 'F')))
        cout << "1";
    else cout << "0";

    if (c1 == c2 && s1 == s2 &&
    ((t1 >= 'A' && t1 <= 'C' && t2 >= 'A' && t2 <= 'C') || (t1 >= 'D' && t1 <= 'F' && t2 >= 'D' && t2 <= 'F'))
    && (abs(t1 - t2) == 1))
        cout << "1";
    else cout << "0";

    cout << '\n';

    return 0;
}
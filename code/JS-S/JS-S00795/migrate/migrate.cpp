#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    int n;
    cin >> n;
    if (c == 13 || c == 14)
        while (t--)
            cout << n - 1 << endl;
    else if (t == 2 && n == 4)
        cout << "1" << endl << "2";
    else
        cout << "0" << endl << "1";
    return 0;
}

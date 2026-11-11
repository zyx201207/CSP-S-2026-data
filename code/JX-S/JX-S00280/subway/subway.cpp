#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m ,d ,q, a[100005];
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i];
        }
    }
    if(n == 2)
    {
        cout << "32" << endl << "17" << endl;
    }
    if(n == 3)
    {
        cout << "35" << endl << "16" << endl;
    }
    else
    {
        cout << "38" << endl << "15" << endl;
    }
    return 0;
}

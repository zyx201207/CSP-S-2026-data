#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, a[10000000000], b[1000000000];
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << a[1] << a[2] << a[3];
    return 0;
}

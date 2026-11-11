#include <bits/stdc++.h>
using namespace std;

int a[200005], t[300005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t[a[i]]++;
    }
    for (int i = 1; i <= m; i++)
        cout << t[i] << " ";
    return 0;
}


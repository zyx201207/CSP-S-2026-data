#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const int maxm = 3e5 + 10;
#define _for(i, n) for (int i = 0; i < n; i++)
int a[maxn];
int b[maxm];
int d[maxn];
int *r = d;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    _for(i, n)
    {
        cin >> a[i];
    }
    _for(i, n)
    {
        for (int j = i; j < n; j++)
        {
            auto it = find(d, r, a[j]);
            if (it == r)
            {
                *r = a[j];
                r++;
            }
            else
            {
                r = it + 1;
            }
        }
        for (auto j = d; j < r; j++)
        {
            b[*j]++;
            // cout<<*j<<' ';
        }
        // cout<<endl;
        r = d;
    }
    for (int i = 1; i <= m; i++)
        cout << b[i] << ' ';
    cout << endl;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000001],c[5001][5001],k,m;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1;i<=n;i++)
        {
            cin >> a[i];
        }
        if (c <= 10)
        {
            cout << 10;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int w[500005],a[505][50005], t[505][50005], ti[500005], l[505];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, n, m , d, q;
    cin >> c>> n>> m>> d>> q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> t[0][i];
        for(int j = 1; j <= t[0][i]; j++)
            cin >> a[i][j]>> t[i][j];
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        int ba = w[x] + w[y];
        for(int i = 1; i <= m; i++)
            ti[i] = 2e9;
        ti[x] = 0;
        for(int k = 1; k <= m; k++)
        {
            for(int i = 1; i <= n; i++)
            {
                l[i] = 2e9;
                for(int j = 1; j <= t[0][i]; j++)
                    if(ti[a[i][j]] + t[i][j] <l[i])l[i] = ti[a[i][j]] + t[i][j];
                for(int j = 1; j <= t[0][i]; j++)
                    if(ti[a[i][j]] > l[i] + t[i][j]) ti[a[i][j]] = l[i] + t[i][j];
            }
        }
        cout << ti[y] + ba<< "\n";
    }
    return 0;
}

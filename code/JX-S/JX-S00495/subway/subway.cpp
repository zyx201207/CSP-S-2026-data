#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;
int c,n,m,d,q;
int w[N];
int k;
int a[N][N],t[N][N];
int x,y;
int ans;
int jieshu;
vector<ll> sum[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i ++)
    {
        cin >> k;
        for (int j = 1; j <= k ; j ++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 1; i <= q; i ++)
    {
        ans = 0;
        jieshu = 0;
        for (int j = 1; j <= n; j ++)
        {
            sum[j].clear();
        }
        cin >> x >> y;
        ans += w[x];
        ans += t[x][x];
        ans += w[y];

        for (int j = x+1; j <= n ; j ++)
            for (int z = 2; z <= m ;z ++)
            {
                for (int k = 1; k <=m; k ++)
                {
                    if (a[x][z] == a[j][k])
                    {
                        sum[j].push_back(a[j][k]);
                    }
                }
            }
        }
        int num = 0;
        bool fs = 1;
        int numn = 0;
        for (int j =x; j <= n ; j ++)
        {
            if (sum[j].empty() != 0)
            {
                num ++;
                if (num > 1)
                {
                    fs = 0;
                    break;
                }
                numn = j;
            }
        }
        if (fs == 1)
        {
            ans += t[x][numn];
            ans += t[numn][numn];
            for (int z = 1; z <= m ;z ++)
            {
                if (a[numn][z] == y)
                {
                    ans += t[numn][z];
                    ans += t[z][z];
                    ans += t[z][y];
                    cout << ans << "\n";
                    jieshu = 1;
                    break;
                }
            }
        }
        for (int j = 2; j <= n ; j ++)
        {
            if(sum[j][1] !=0 && sum[j][1] <= y)
            {
                for (int z = 1;z <= m; z ++)
                {
                    break;//
                }
            }
            else if (sum[j][1] !=0 && sum[j][1] > y)
            {
                jieshu = 1;
                break;
            }
        }
    }
}

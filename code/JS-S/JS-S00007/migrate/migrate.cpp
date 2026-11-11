#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int c,T;
const int maxn=5005;
const int maxm=2e6+5;
int n,d;
int a[maxm];
vector<int> e[maxn];
int cnt[maxn][maxn];
int dis[maxn][maxn];
inline void dij(int s)
{
    queue<pii> q;
    q.push({0,s});
    dis[s][s]=0;
    cnt[s][s]=1;
    while (q.size())
    {
        int u=q.front().second;
        int d=q.front().first;
        q.pop();
        for (auto v:e[u])
        {
            if (dis[s][u]+1<dis[s][v])
            {
                dis[s][v]=dis[s][u]+1;
                cnt[s][v]=cnt[s][u];
                q.push({dis[s][v],v});
            }
            else if (dis[s][u]+1==dis[s][v])
            {
                cnt[s][v]+=cnt[s][u];
            }
        }
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> c>>T;
    if (c<=10)
    {
        while (T--)
        {
            int ans=0;
            cin >> n >> d;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++) 
                {
                    dis[i][j]=0x7f7f7f7f;
                    cnt[i][j]=0;
                }
            for (int i=1;i<=n;i++) e[i].clear();
            for (int i=1;i<=n;i++) cin >> a[i];
            for (int i=1;i<=n;i++)
                for (int j=i+1;j<=n;j++)
                    if (a[i]+d>=a[j]) e[i].push_back(j);
            for (int i=1;i<=n;i++) dij(i);
            for (int i=1;i<=n;i++)
                for (int j=i+1;j<=n;j++)
                    if (cnt[i][j]==2) 
                    {
                        ans++;
                    }
            cout << ans << '\n';
        }
    }
    else 
    {
        while (T--)
        {
            cin >> n >> d;
            for (int i=1;i<=n;i++) cin >> a[i];
            int D=a[2]-a[1];
            if (d<2*D || d>=3*D)
            {
                cout << 0 << endl;
                continue;
            }
            else
            {
                cout << n-3 << endl;
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=5e2+10;
const int M=5e5+10;

ll dis[N][N],a[M],Type,n,m,D,Q;
vector<pii> e[M];

inline void Solve()
{
    cin >> Type >> n >> m >> D >> Q;
    for(int i=1;i<=m;i++) cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        while(k--)
        {
            int x,y;
            cin >> x >> y;
            e[x].push_back({i,y});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(pii u:e[i])
            for(pii v:e[i])
                dis[u.first][v.first]=min(dis[u.first][v.first],0ll+u.second+v.second);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(Q--)
    {
        int x,y;
        cin >> x >> y;
        ll ans=5e18;
        for(pii u:e[x]) for(pii v:e[y]) ans=min(ans,a[x]+u.second+dis[u.first][v.first]+v.second+a[y]);
        cout << ans << '\n';
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
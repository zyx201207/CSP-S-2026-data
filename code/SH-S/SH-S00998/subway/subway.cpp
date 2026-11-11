#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=509;
const int M=500005;
struct Edge{
    int to;
    ll len;
};
int n,m,Q;
int d;
ll w[M];
ll ans;
vector<Edge> sub[M];
ll e[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int C;
	cin>>C>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            sub[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        e[i][j]=1e18;
    for(int i=1;i<=n;i++)e[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(auto a:sub[i])
          for(auto b:sub[i])
            {
                if(a.to==b.to)continue;
                e[a.to][b.to]=min(e[a.to][b.to],a.len+b.len);
            }
    }
    for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
    for(int q=1;q<=Q;q++)
    {
        int x,y;
        cin>>x>>y;
        ans=1e18;
        for(auto a:sub[x])
          for(auto b:sub[y])
            ans=min(ans,a.len+b.len+e[a.to][b.to]);
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
	return 0;
}

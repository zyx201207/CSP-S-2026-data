#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define endl '\n'
using namespace std;
const int maxn=505,maxm=5e5+5;
vector<pair<int,int> > g[maxm],ng[maxn];
int a[maxm];
int _,n,m,d,q;
int f[maxn][maxn];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;cin>>x>>y;
			g[x].push_back({i,y});
			ng[i].push_back({x,y});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0;
		for(auto to:ng[i])
		{
			for(auto nxt:g[to.first])
			{
				int now=nxt.first;
				f[i][now]=f[now][i]=min(f[i][now],nxt.second+to.second);
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int u,v,ans=inf;cin>>u>>v;
		for(auto x:g[u]) for(auto y:g[v]) ans=min(ans,x.second+y.second+f[x.first][y.first]);
		cout<<ans+a[u]+a[v]<<endl;
	}
	return 0;
}
/*
Êý×é´óÐ¡¿´ÁËÂð£¿
²¿·Ö·ÖÄÃÁËÂð£¿
ÄÚ´æËãÁËÂð£¿
*/

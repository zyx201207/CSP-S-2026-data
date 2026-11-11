#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e2+7;
const int maxm=5e5+7;
struct node
{
	int x;
	ll t;
};
ll f[maxn][maxn],w[maxm];
vector<node> metro[maxm];
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
//	freopen("subway7.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	int id,n,m,d,q;
	cin>>id>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int y;
			ll z;
			cin>>y>>z;
			metro[y].push_back({i,z});
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<metro[i].size();j++)
		{
			node u=metro[i][j];
			for(int k=0;k<metro[i].size();k++)
			{
				if(k==j)
					continue;
				node v=metro[i][k];
				f[u.x][v.x]=min(f[u.x][v.x],u.t+v.t);
			}
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<metro[x].size();i++)
		{
			node u=metro[x][i];
			for(int j=0;j<metro[y].size();j++)
			{
				node v=metro[y][j];
				ans=min(ans,f[u.x][v.x]+u.t+v.t);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
//quxinb

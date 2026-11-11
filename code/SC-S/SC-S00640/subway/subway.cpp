#include <bits/stdc++.h>

using namespace std;

const int N=5e2+10,M=5e5+10;
struct Node
{
	long long id,w;
};
vector <Node > v[M],rs[N];
long long f[N][N],c,n,m,d,q,w[M],x,y,k;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			rs[i].push_back({x,y});
			v[x].push_back({i,y});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(Node k:rs[i])
		{
			for(Node p:v[k.id]) f[i][p.id]=min(f[i][p.id],p.w+k.w);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	} 
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		long long res=1e18;
		for(Node k:v[x])
		{
			for(Node p:v[y])
			{
				res=min(f[k.id][p.id]+k.w+p.w,res);
			}
		}
		cout<<res+w[x]+w[y]<<"\n";
	}
	return 0;
}
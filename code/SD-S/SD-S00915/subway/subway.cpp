#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=520;
const LL M=500520;
LL V[M];
struct node
{
	LL w,v;
};
vector <node> a[M];
LL t[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	LL i,j,o;
	LL c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (i=1;i<=m;i++) cin>>V[i];
	for (i=1;i<=n;i++)
	{
		LL k;
		cin>>k;
		for (j=1;j<=k;j++)
		{
			LL w,v;cin>>w>>v;
			a[i].push_back({n+w,v});
			a[n+w].push_back({i,v});
		}
	}
	for (i=1;i<=n;i++) for (j=1;j<=n;j++) if (i!=j) t[i][j]=1e18;
	for (i=n+1;i<=n+m;i++)
	{
		LL u,v;
		for (u=0;u<a[i].size();u++)
		{
			for (v=u+1;v<a[i].size();v++)
			{
				t[a[i][u].w][a[i][v].w]=min(t[a[i][u].w][a[i][v].w],a[i][u].v+a[i][v].v);
				t[a[i][v].w][a[i][u].w]=min(t[a[i][v].w][a[i][u].w],a[i][u].v+a[i][v].v);
			}
		}
	}
	for (o=1;o<=n;o++) for (i=1;i<=n;i++) for (j=1;j<=n;j++) t[i][j]=min(t[i][j],t[i][o]+t[o][j]);
	while (q--)
	{
		LL x,y;
		cin>>x>>y;
		LL ans=1e18;
		for (auto u:a[n+x]) for (auto v:a[n+y]) ans=min(ans,t[u.w][v.w]+u.v+v.v);
		cout<<ans+V[x]+V[y]<<"\n";
	}
	return 0;
}

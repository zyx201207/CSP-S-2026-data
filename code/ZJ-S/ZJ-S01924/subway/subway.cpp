#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=50,M=50;
const ll INF=0x7f7f7f7f7f7f7f7f;
int m,d,n,q,c;
ll w[N],a[N][M],t[N][M],minn=INF;
int x,y,k[N];
vector<int>v[N];
bool vis[M];
void dfs(int u,ll ti)
{
	if(u==y)
	{
		minn=min(ti,minn);
		return;
	}
//	cout<<"q "<<u<<"\n";
	vis[u]=1;
	for(int h:v[u])
		for(int i=1;i<=k[h];i++)
		{
			if(vis[a[h][i]])
				continue;
			dfs(a[h][i],ti+t[h][i]+t[h][u]);
			vis[a[h][i]]=0;
//			cout<<"h "<<u<<"\n";
		}
		

}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[m];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		dfs(x,0);
		cout<<minn+w[y]+w[x]<<"\n";
	}
	return 0;
}
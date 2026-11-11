#include <bits/stdc++.h>
using namespace std;
const int M=500005;
const int N=505;
int n,m,d,q,w[M],srd[N][N],vis[N],t[N][M];
vector <int> vec[M],a[N];
vector <pair<int,int> > rd[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			a[i].push_back(x),t[i][x]=y;
			vec[x].push_back(i);
		}
		for(int j=1;j<=n;j++) srd[i][j]=1e9;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			for(int k=0;k<vec[i].size();k++)
			{
				if(j==k) continue;
				int x=vec[i][j],y=vec[i][k];
				rd[x].push_back(make_pair(y,t[x][i]+t[y][i]));
			}
		}
	}
	while(q--)
	{
		int x,y,ans=1e9;
		cin>>x>>y;
		ans+=w[x]+w[y];
		for(int i=0;i<vec[y].size();i++) vis[vec[y][i]]=1;
		for(int i=0;i<vec[x].size();i++)
		{
			if(vis[i]==1)
			{
				ans=min(ans,t[i][x]+t[i][y]);
			}
		}
		cout<<ans<<"\n";
		for(int i=0;i<vec[y].size();i++) vis[vec[y][i]]=0;
	}
	return 0;
}
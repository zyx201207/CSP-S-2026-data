#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],ans,vis[500010],t[510][500010];
int x1,y1;
struct node
{
	int me,ti;
};
vector<int> g[500010];
vector<node> p[500010];
void dfs(int x,int spt,int pz) //x:当前站，spt:所用步数，pz:当前所在地铁 
{
	if(x==y1)
	{
		ans=min(spt,ans);
		return;
	}
	// u:遍历本站地铁 r:遍历本站地铁经过站 
	for(auto u:g[x])
	{
		for(auto r:p[u])
		{
			if(r.me==x || vis[r.me]) continue;
			vis[r.me]=1;
			dfs(r.me,spt+r.ti+t[x][pz],u);
			vis[r.me]=0;
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int me1,ti1;
			cin>>me1>>ti1;
			t[i][j]=ti1;
			p[i].push_back({me1,ti1});
			g[me1].push_back(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x1>>y1;
		memset(vis,0,sizeof(vis));
		ans=INT_MAX;
		dfs(x1,0,0);
		cout<<ans+w[x1]+w[y1]<<endl;
	}
	return 0;
}
  

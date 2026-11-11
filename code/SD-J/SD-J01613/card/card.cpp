#include<bits/stdc++.h>
using namespace std;
struct node
{
	int w,q;
};
int n,m,a[500005],maxx[300005],jb[500005];
vector<int>js[500005];
vector<node>g[300005];
void dfs(int x,int step)
{
	jb[x]++;
	maxx[a[x]]=max(maxx[a[x]],jb[x]);
	bool f=0;
	for(int i=0;i<g[x].size();i++)if(g[x][i].q==1)dfs(g[x][i].w,step+1),f=1;
	if(f==0)for(int i=0;i<g[x].size();i++)dfs(g[x][i].w,step+1);
}
int main() 
{
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=js[a[i]].size();
		if(x>0)
			g[js[a[i]][x-1]].push_back({i,1});
		js[a[i]].push_back(i);
		if(i>1)g[i-1].push_back({i,2});
	}
	for(int i=1;i<=n;i++)
		dfs(i,0);
	for(int i=1;i<=m;i++)
		cout<<maxx[i]<<" ";
	return 0;
}

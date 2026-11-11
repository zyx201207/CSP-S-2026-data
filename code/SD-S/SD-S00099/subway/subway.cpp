#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,m,n,d,q;
struct node{
	int v,val;
};
vector<node> u[50005];
int w[N],ans;
bool vis[N];
void dfs(int x,int vv,int y)
{
	if(x==y)
	{
		ans=max(ans,vv);
		return;
	}
	for(auto a:u[x])
	{
		if(vis[a.v]==1)
		{
			return;
		}
		vis[x]=1;
		dfs(a.v,vv+a.val,y);
	}
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
	int k,a,t;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			u[i].push_back({a,t});
			u[a].push_back({i,t});
		}
	}
	int x,y;
	for(int i=1;i<=q;i++)
	{
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		dfs(x,0,y);
		cout<<ans+w[x]+w[y]<"\n";
	}
	return 0;
}
//jin nian shi di er ci kao le . qu nian kao J hun de 2= . jin nian chu sai S guo le J mei guo 
//kao S ganjue sha ye bu hui .wo shi qu.  ming nian chu san hai you jihui zailai ba

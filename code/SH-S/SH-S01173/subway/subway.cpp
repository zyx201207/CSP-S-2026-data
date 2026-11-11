#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,r,cost;
int w[500005],a[500005],x,y,ans=1e9;
vector<int> p[500005];
int book[500005];
void dfs(int now,int step,int ed)
{
	if(now==ed)
	{
		ans=min(ans,step);
		return;
	}
	
	if(book[now]) return;
	book[now]=true;
	int bsize=p[now].size();
	for(int i=0;i<bsize;i++)
	{
		dfs(p[now][i],step+1,ed);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int fa;
		cin>>fa>>cost;
		for(int j=2;j<=k;j++)
		{
			int a;
			cin>>a>>cost;
			p[fa].push_back(a);
			p[a].push_back(fa);
			fa=a;
		}
	}
	while(r--)
	{
		cin>>x>>y;
		dfs(x,0,y);
		cout<<ans;
		cout<<((ans*cost)+w[x]+w[y])<<endl;
		memset(book,0,sizeof(book));
		ans=1e9;
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int c,n,d,p,m;
long long w[500005],vis[500005],ans;
struct mmm
{
	int k;
	vector<long long>a;
	vector<long long>t;
};
struct pointss
{
	vector<int>p;
};
mmm a[505];
pointss b[500005];
void dfs(int sts,int eds,long long tsum)
{
	if(sts==eds)
	{
		ans=min(ans,tsum);
		return;
	}
	for(int i=0;i<b[sts].p.size();i++)
	{
		for(int j=0;j<a[j].k;j++)
		{
			if(vis[a[j].a[i]]==0)
			{
				vis[a[j].a[i]]=1;
				dfs(a[j].a[i],eds,tsum);
				vis[a[j].a[i]]=0;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k;
		for(int j=1;j<=a[i].k;j++)
		{
			long long xx1,xx2;
			cin>>xx1>>xx2;
			a[i].a.push_back(xx1);
			a[i].t.push_back(xx1);
			b[xx1].p.push_back(i);
		}
	}
	while(p--)
	{
		int u,v;
		cin>>u>>v;
		memset(vis,0,sizeof(vis));
		vis[u]=0,vis[v]=0;
		ans=1e18;
		dfs(u,v,0);
		if(ans==1e18)
		{
			cout<<2<<endl;
		}
		else
		{
			cout<<ans<<endl;
		}
	}
	return 0;
}

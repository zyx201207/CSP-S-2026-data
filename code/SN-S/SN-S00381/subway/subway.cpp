#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int v,id;
};
int c,n,m,d,q;

int vis[500005],tim=0;//tim:shijianchuo
int be,en;
vector<node>e[500005];
int w[500005];
vector<int>ID[500005];
int t[5005][505];
int ans=1000000000000000000;
void dfs(int u,int tot,int uid)
{
	if(u==en)
	{
		ans=min(ans,tot+t[u][uid]);
		return ;
	}
	for(node i:e[u])
	{
		
		int v=i.v;
		int id=i.id;
		if(vis[v]==tim)continue;
		vis[v]=tim;
		
		if(id==uid)
		{
			dfs(v,tot,uid);
		}
		else
		{
			dfs(v,tot+t[u][uid]+t[u][id],id);
			//cout<<u<<" "<<v<<" "<<id<<" "<<uid<<endl;
		}
		vis[v]=0;
	
	}

}
void solve()
{
	ans=1000000000000000000;
	tim++;
	scanf("%lld%lld",&be,&en);
	vis[be]=tim;
	for(auto idd:ID[be])
	{
		dfs(be,w[be]+w[en]+t[be][idd],idd);
		tim++;
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		int last=0;
		for(int j=1;j<=x;j++)
		{
			int fir,sec;cin>>fir>>sec;
			t[fir][i]=sec;
			if(j>1)
			{
				e[fir].push_back(node{last,i});
				ID[fir].push_back(i);
			}
			if(j>1)
			{
				e[last].push_back(node{fir,i});
				ID[last].push_back(i);
			}
			last=fir;
			
		}
	}
	while(q--)
	{
		solve();
	}
	return 0;
}

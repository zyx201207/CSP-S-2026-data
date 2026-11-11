#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=2e4+5;
int c,n,m,d,qq,k[M],mp[N][M],ans[M][M];
ll w[M],dp[M];
bool vis[M][N];
vector<int> f[M];
struct Node{
	int id;
	ll v;
}a[N][M];

struct node{
	int id;
	ll value;
	int now;
	bool operator <(const node&x)const{
		return value>x.value;
	}
};
priority_queue<node> q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j].id>>a[i][j].v;
			mp[i][a[i][j].id]=j;
			f[a[i][j].id].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(dp,0x3f,sizeof(dp));
		memset(vis,0,sizeof(vis));
		dp[i]=0;
		for(auto j:f[i])
		{
			node x={i,dp[i]+a[j][mp[j][i]].v,j};
			q.push(x);
		}
		while(!q.empty())
		{
			node kl=q.top();
			q.pop();
			if(vis[kl.id][kl.now])
				continue;
			vis[kl.id][kl.now]=1;
			for(auto p:f[kl.id])
			{
				for(int lll=1;lll<=k[p];lll++)
				{
					int l=a[p][lll].id;
					if(l==kl.id) 
						continue;
					if(!vis[l][p]&&p==kl.now)
					{
						if(dp[a[p][mp[p][l]].id]>kl.value+a[p][mp[p][l]].v)
						{
							dp[a[p][mp[p][l]].id]=kl.value+a[p][mp[p][l]].v;
							q.push(node{a[p][mp[p][l]].id,dp[a[p][mp[p][l]].id],kl.now});
						}
					}
					else if(!vis[l][p]&&p!=kl.now)
					{
						if(dp[a[p][mp[p][l]].id]>kl.value+a[kl.now][mp[p][kl.id]].v+a[p][mp[p][kl.id]].v+a[p][mp[p][l]].v)
						{
							dp[a[p][mp[p][l]].id]=kl.value+a[p][mp[p][kl.id]].v+a[p][mp[p][l]].v;
							q.push(node{a[p][mp[p][l]].id,dp[a[p][mp[p][l]].id],p});
						}
					}
				}
			}
		}
		for(int j=i+1;j<=m;j++)
		{
			ans[i][j]=dp[j];ans[j][i]=dp[j];
		}
	}
	while(qq--)
	{
		int u,v;
		cin>>u>>v;
		cout<<ans[u][v]+w[u]+w[v]<<"\n";
	}
	return 0;
}

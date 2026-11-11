#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int n,k,head[N],cnt,fa[N],ans,res,s1,s2,s3,dep[N];
struct node{
	int ne,to;
}e[N<<1];
void add(int u,int v)
{
	cnt++;
	e[cnt].ne=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
void dfs(int u,int fat)
{
	fa[u]=fat;
	dep[u]=dep[fat]+1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].to;
		if(v==fat) continue;
		dfs(v,u);
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		dep[0]=-1;
		cin>>n>>k;
		cnt=0,ans=1e18;
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v),add(v,u);
		}
		for(int i=1;i<=n;i++)
		{
			s1=0,s2=0,s3=0;
			dfs(i,0); 
			for(int j=1;j<=n;j++)
			{
				if(dep[j]>s1) s3=s2,s2=s1,s1=dep[j];
			}
			res+=s2;
			if(s1%2==1) s1++;
			res+=max(s1/2,s3);
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
	return 0;
}


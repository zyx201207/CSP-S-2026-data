#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int maxn=1e4+10;
int n,k;
vector<int>e[maxn];
bool vis[maxn];
int fa[maxn];
void init()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
}
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void add(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y)
	{
		fa[x]=y;
	}
}
bool check()
{
	init();
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			for(auto v:e[i])
			{
				if(vis[v]==1)add(v,i);
			}
		}
	}
	int cnt=0,id1,id2;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			if(cnt==0)id1=find(i),cnt++;
			else 
			{
				if(cnt==1)
				{
					if(id1!=find(i))
					{
						id2=find(i);
						cnt++;
					}
				}
				else
				{
					if(id1!=find(i)&&id2!=find(i))return 0;
				}
			}
		}
	}
	return 1;
}
int val;
void dfs(int u,int ff,int step,int opt)
{
	if(opt==1)
	{
		if(vis[u]==1)val=min(val,step);
	}
	else 
	{
		if(vis[u]==0)val=max(val,step);
	}
	for(auto v:e[u])
	{
		if(v==ff)continue;
		dfs(v,u,step+1,opt);
	}
}
int get_val()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			val=1e9;
			dfs(i,0,0,1);
			cnt=max(cnt,val);
		}
	}
	return cnt;
}
int ans=1e9;
void dfs(int id,int x)
{
	if(x>=k)
	{
		if(check())
		{
//			cout<<"\n";
//			for(int i=1;i<=n;i++)
//			{
//				if(vis[i]==1)
//				{
//					cout<<i<<" ";
//				}
//			}
			ans=min(ans,get_val());
//			cout<<ans;
//			cout<<"\n";
		}
		return;
	}
	for(int i=id;i<=n;i++)
	{
		vis[i]=1;
		dfs(i+1,x+1);
		vis[i]=0;
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	ans=1e9;
	dfs(1,0);
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)e[i].clear();
	return;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _;
	cin>>_>>_;
	while(_--)
	{
		solve();
	}
	return 0;
} 
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

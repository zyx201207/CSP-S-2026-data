#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

const int N=1e6+6;

int c;

int t;

int n,k;

vector<int> vec[N];
bool vis[N];

bool viss[N];
void dfs1(int u)
{
	viss[u]=1;
	for(auto v:vec[u])
	{
		if(viss[v]||!vis[v]) continue;
		
		dfs1(v);
	}
	
	return ;
}

struct que
{
	int u;
	int s;
};
bool visss[N];

int bfs(int u)
{
	for(int i=1;i<=n;i++) visss[i]=0;
	queue<que> q;
	q.push({u,0});
	visss[u]=1;
	
	while(!q.empty())
	{
		int u=q.front().u;
		int s=q.front().s;
		q.pop();
		
		for(auto v:vec[u])
		{
			if(visss[v]) continue;
			
			visss[v]=1;
			if(vis[v])
			{
				return s+1;
			}
		}
	}
}

int ans=N;

void dfs(int i,int s)
{
	if(i>n)
	{
		if(s==k)
		{
			int ss=0;
			for(int i=1;i<=n;i++) viss[i]=0;
			for(int i=1;i<=n;i++)
			{
				if(!viss[i]&&vis[i])
				{
					ss++;
					dfs1(i);
				} 
			}
			
			if(ss>2) return ;
			
			int maxn=0;
			for(int i=1;i<=n;i++)
			{
				if(!vis[i])
				{
					maxn=max(maxn,bfs(i));
				}
			}
			/*
			if(maxn==1)
			{
				cout<<ss<<"\n";
				for(int i=1;i<=n;i++) if(vis[i]) cout<<i<<" ";
				cout<<"\n";
			
			}
			*/
			ans=min(ans,maxn);
		}
		
		return ; 
	}
	
	vis[i]=1;
	dfs(i+1,s+1);
	
	vis[i]=0;
	dfs(i+1,s);
	
	return ;
}

void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) vec[i].clear();
	
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	
	if(n==k)
	{
		cout<<"0\n";
		return ; 
	}
	if(k==2)
	{
		cout<<"1\n";
		return ;
	}
	if(n<=10)
	{
		ans=N;
		dfs(1,0);
		cout<<ans<<"\n";
	}
	
	return ;
}

int main() {
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c;
	cin>>t;
	while(t--) solve();
	
	return 0;
}

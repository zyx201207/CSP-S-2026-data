#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e6+7;
int n,k;
struct edge
{
	int to;
	int nxt;
}e[N<<1];
int head[N],tot;
void add(int u,int v)
{
	e[++tot]={v,head[u]};
	head[u]=tot;
}
int dis[20];
void dfs(int u,int c,int st)
{
	dis[u]=c;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(dis[v])
			continue;
		if(!((st>>(v-1))&1))
			continue;
		dfs(v,u,st);
	}
}
bool check_all(int st)
{
	memset(dis,0,sizeof dis);
	int cnt=0;
	for(int i=0;i<n;i++)
		if(((st>>i)&1) && !dis[i+1])
			dfs(i+1,++cnt,st);
//	cout<<cnt<<'\n';
	return cnt==2;
//	cout<<cnt;
}
int check(int st)
{
	if(!check_all(st))
	{
	
		return 1e9;
	}
		
	memset(dis,0,sizeof dis);	
	queue<int>q;
	for(int i=0;i<n;i++)
		if((st>>i)&1)
		{
			q.push(i+1);
			dis[i+1]=1;
		}

	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(dis[v])
				continue;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}	
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dis[i]-1);
	return ans;
}
void solve()
{
	cin>>n>>k;
	tot=0;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	int ans=1e9;
	for(int i=1;i<(1<<n);i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
			if((i>>j)&1)
				cnt++;
		if(cnt>k)
			continue;
		ans=min(ans,check(i));
//		if(check(i)==1)
//			cout<<bitset<10>(i).to_string()<<'\n';
	} 
	cout<<ans<<'\n';
	
	for(int i=1;i<=n;i++)
		head[i]=0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int C,T;
	cin>>C>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}

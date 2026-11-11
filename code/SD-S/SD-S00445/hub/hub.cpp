#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define ull unsigned long long
#define ll long long
#define endl '\n'
using namespace std;
int ans=1e9,b[100007],tot,dis[100007],n,k;
vector<int>v[100007];
void check2(int x,int fa)
{
	if(b[x]==1&&b[fa]==0) tot++;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(y==fa) continue;
		check2(y,x); 
	}
}
void bfs(int x)
{
	queue<int>q;
	q.push(x);
	dis[x]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop(); 
		for(int i=0;i<v[x].size();i++)
		{
			if(dis[v[x][i]]>dis[x]+1) dis[v[x][i]]=dis[x]+1,q.push(v[x][i]);
		}
	}
}
int check()
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e9;
	}
	int maxx=0;
	tot=0;
	check2(1,0);
	if(tot>2) return 1e9;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1) bfs(i);
	}
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,dis[i]);
	}
	return maxx;
} 
void dfs(int x,int y)
{
	if(x==n+1&&y==k)
	{
		ans=min(ans,check());
		return;
	}
	if(x==n+1) return ;
	if(y<k) 
	{
		b[x]=1;
		dfs(x+1,y+1);
		b[x]=0;
	}
	dfs(x+1,y);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	IO;
	int ct,T;
	cin>>ct>>T;
	while(T--)
	{
		ans=1e9;
		memset(b,0,sizeof(b));
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(n<=30)
		{
			dfs(1,0);
			cout<<ans<<endl;
			continue;
		}
		if(k==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i==j) continue;
					b[i]=1;
					b[j]=1;
					ans=min(ans,check());
					b[i]=0;
					b[j]=0; 
				}
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
/*
5 2
1 2
2 3
3 4
4 5
*/

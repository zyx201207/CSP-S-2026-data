#include<bits/stdc++.h>
using namespace std;
const int N=4010;
int d[N],dis[N][N];
int n,k;
vector<int> G[N];
bool ds[N][N];
void solve(int s)
{
	for(int i=1;i<=n;i++) d[i]=N;
	queue<int> q;
	q.push(s);
	d[s]=0;
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		for(int i:G[cur])
		{
			if(d[i]==N)
			{
				d[i]=d[cur]+1;
				q.push(i);
			}
		}
	}
}
vector<int> v;
int ans=N;
void check()
{
	int res=0;
	for(int i:v)
	{
		for(int j:v)
		{
			res+=ds[i][j];
		}
	}
	if(res<k-2) return;
	int p=0;
	/*
	for(int i:v)
	{
		cout<<i<<' ';
	}
	cout<<'\n';*/
	for(int i=1;i<=n;i++)
	{
		d[i]=N;
		for(int j:v)
		{
			d[i]=min(d[i],dis[j][i]);
		}
		p=max(p,d[i]);
		if(p>=ans) return;
	}
	//cout<<p<<'\n';
	ans=min(ans,p);
}
void dfs(int cur,int sum)
{
	if(sum>k) return;
	if(n-cur+1<k-sum) return;
	if(cur>n)
	{
		check();
		return;
	}
	v.push_back(cur);
	dfs(cur+1,sum+1);
	v.pop_back();
	dfs(cur+1,sum);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ds[i][j]=0;
		ans=N;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
			ds[u][v]=1;
		}
		//cout<<ans<<'\n';
		for(int i=1;i<=n;i++)
		{
			solve(i);
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=d[j];
			}
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int dist[2000110];
int n,d;
int a[2000010];
int v[2000110];
void cl()
{
	for(int i=1;i<=2000010;i++) 
	{
		dist[i]=0;
		v[i]=2000010;
	}
}
/*
void bfs(int s,int n)
{
	for(int i=1;i<=n;i++)
	{
		d[i]=-1;
	}
	queue<int>q;
	q.push_back(s);
	d[s]=0;
	while(!q.empty())
	{
		vector<int>g;
		for(int v:g)
		{
			if(d[i]!=-1)
			{
				continue;
			}
			d[v]=d[u]+a[i];
		}
	}
}
*/
void dfs(int s,int step)
{
	if(s>=n)
	{
		return ;
	}
	if(step==v[s])
	{
		dist[s]++;
	}
	int i=s+1;
	v[s]=min(v[s],step);
	while(a[i]-a[s]<=d)
	{
		dfs(s+i,step++);
		i++;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int ans;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cl();
		dfs(1,0);
		for(int i=1;i<=2000010;i++)
		{
			if(dist[i]==2)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}

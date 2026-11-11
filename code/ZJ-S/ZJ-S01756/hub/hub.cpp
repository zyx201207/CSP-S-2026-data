#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> v[30];
vector<int> S;
int vis[30];
int mx;
int fa[30];
int find(int x)
{
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
int count1(int x)
{
	int cnt=0;
	while(x)
	{
		cnt+=(x&1);
		x/=2;
	}
	return cnt;
}
void bfs()
{
	queue<pair<int,int>> q;
	for(int i=0;i<S.size();i++)
	{
		q.push({S[i],0});
		vis[S[i]]=1;
	}
	while(!q.empty())
	{
		int tmp=q.front().first;
		int tt=q.front().second;
		q.pop();
		mx=max(mx,tt);
		for(int i=0;i<v[tmp].size();i++)
		{
			int y=v[tmp][i];
			if(!vis[y])
			{
				vis[y]=1;
				q.push({y,tt+1});
			}
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int answer=1e9;
		for(int s=0;s<(1<<n);s++)
		{
			if(count1(s)!=k)
			{
				continue;
			}
			S.clear();
			for(int j=1;j<=n;j++)
			{
				fa[j]=j;
				vis[j]=0;
				if((s>>j-1)&1)
				{
					S.push_back(j);
				}
			}
			for(int i=0;i<S.size();i++)
			{
				int y=S[i];
				vis[y]=1;
				for(int j=0;j<v[y].size();j++)
				{
					int yy=v[y][j];
					if(vis[yy])
					{
						fa[y]=find(yy);
					}
				}
			}
			int c=0;
			for(int i=0;i<S.size();i++)
			{
				if(find(S[i])==S[i])
				{
					c++;
				}
			}
			if(c>2)
			{
				continue;
			}
			mx=0;
			bfs();
			answer=min(answer,mx);
		}
		cout<<answer<<'\n';
	}
	return 0;
}

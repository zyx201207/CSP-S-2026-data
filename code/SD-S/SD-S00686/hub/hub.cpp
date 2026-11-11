#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define ull unsigned long long
#define ll long long
#define endl '\n'
using namespace std;
int n,k;
vector<int>t[2000010];
bool v[2000010];
int ans;
bool o[2000010];
int c[2000010];
void ds(int x,int fa)
{
	o[x]=1;
	for(auto e:t[x])
	{
		if(e==fa||!v[e])
		{
			continue;
		}
		ds(e,x);
	}
	return;
}
int check()
{
	for(int i=1;i<=n;i++)
	{
		o[i]=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		c[i]=11451414;
		if(v[i]&&!o[i])
		{
			cnt++;
			ds(i,0);
		}
	}
	if(cnt>2)
	{
		return 1145141919ll;
	}
	cnt=0;
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			continue;
		}
		while(!q.empty())
		{
			q.pop();
		}
		q.push(i);
		c[i]=0;
		while(!q.empty())
		{
			int p=q.front();
			q.pop();
			if(v[p])
			{
				c[i]=0;
			}
			for(auto e:t[p])
			{
				if(c[p]+1>=c[e])
				{
					continue;
				}
				c[e]=c[p]+1;
				q.push(e);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cnt=max(cnt,c[i]);
	}
	return cnt;
}
void dfs(int x,int fa,int f,int y)
{
	if(y==k)
	{
		ans=min(ans,check());
		return;
	}
	for(auto e:t[x])
	{
		if(e==fa)
		{
			continue;
		}
		v[e]=1;
		dfs(e,x,1,y+1);
		v[e]=0;
		dfs(e,x,0,y);
	}
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	IO;
	int qwe;
	cin >> qwe;
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i=1;i<=n;i++)
		{
			t[i].clear();
			v[i]=0;
			o[i]=0;
			c[i]=0;
		}
		ans=1145141919;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin >> u >> v;
			t[u].push_back(v);
			t[v].push_back(u);
		}
		dfs(1,0,0,0);
		v[1]=1;
		dfs(1,0,1,1);
		cout << ans << endl;
	}
	return 0;
}


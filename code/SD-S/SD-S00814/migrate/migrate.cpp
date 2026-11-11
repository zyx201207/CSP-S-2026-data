//I love Á÷Ó© forever
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N=2e6+5;
struct node
{
	int l,r;
}a[N];
int ID,t,n;
long long d;
long long nums[N];
vector<int> to[N];
long long dis[N];
bool check[N];
long long ans[N];
void bfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		check[i]=0;
		dis[i]=1000000000000000000;
		ans[i]=0;
	}
	dis[x]=0;
	ans[x]=1;
	priority_queue<pair<long long ,int >,vector<pair<long long,int> >,greater<pair<long long,int > > > qq;
	qq.push({0,x});
	while(!qq.empty())
	{
		long long w=qq.top().first;
		int now=qq.top().second;
		qq.pop();
		if(ans[now]>2)
		{
			continue;
		}
		if(check[now])
		{
			continue;
		}
		check[now]=1;
		for(auto nxt:to[now])
		{
			if(dis[nxt]>dis[now]+1)
			{
				dis[nxt]=dis[now]+1;
				ans[nxt]=ans[now];
				qq.push({dis[nxt],nxt});
			}
			else if(dis[nxt]==dis[now]+1)
			{
				ans[nxt]+=ans[now];
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>ID>>t;
	while(t--)
	{
		cin>>n>>d;
		int t=0;
		long long D=0;
		for(int i=1;i<=n;i++)
		{
			cin>>nums[i];
		}
		int l=1,r=1;
		for(int i=1;i<=n;i++)
		{
			while(r<=n&&nums[r]-nums[i]<=d)
			{
				r++;
			}
			r-=1;
			while(l<i&&nums[i]-nums[l]>d)
			{
				l++;
			}
			a[i].l=l;
			a[i].r=r;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=a[i].r;j++)
			{
				if(i==j)
				{
					continue;
				}
				to[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=i+1;j<=n;j++)
			{
				if(ans[j]==2)
				{
					t++;
				}
			}
		}
		cout<<t<<'\n';
		for(int i=1;i<=n;i++)
		{
			to[i].clear();
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

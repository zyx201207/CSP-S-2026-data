#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int c,t;
ll n,d;
ll a[2000005];
int st[305][305][305];
struct node
{
	ll x;
	ll st;
};
queue<node>q;
void bfs(int u)
{
	q.push(node{u,0});
	while(!q.empty())
	{
		node tmp=q.front();
		int x=tmp.x;
		int stp=tmp.st;
		q.pop();
		for(int i=x+1;i<=n;i++)
		{
			if(a[i]-a[x]<=d)
			{
				st[u][i][stp+1]++;
				q.push(node{i,stp+1});
			}
			else
			{
				break;
			}
		}
	}
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--)
	{
		bool spa=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i>=3)
			{
				if(a[i]-a[i-1]!=a[i-1]-a[i-2])
				{
					spa=0;
				}
			}
		}
		if(spa)
		{
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			bfs(i);
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(st[i][j][k]>>0)
					{
						if(st[i][j][k]==2)
						{
							ans++;
						}
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					st[i][j][k]=0;
				}
			}
		}
	}
	
	return 0;
}
//This is our last song,which will be passed down forever
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

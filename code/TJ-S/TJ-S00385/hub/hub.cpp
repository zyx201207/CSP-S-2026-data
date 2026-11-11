#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node
{
	int to;
	int next;
};

Node edge1[100];
int head1[100];
int tot1;
bool is[100];
bool vis[100];

int ans = 1e18;

inline void init()
{
	tot1 = 0;
	memset(head1 , -1 , sizeof(head1));
	memset(is , false , sizeof(is));
	return;
}

inline void add(int x , int y)
{
	edge1[++tot1].to = y;
	edge1[tot1].next = head1[x];
	head1[x] = tot1;
	return;
}

bool check(int n)
{
	int cnt = 0;
	queue <int> q;
	memset(vis , false , sizeof(vis));
	for(int i = 1 ; i <= n ; i++)
	{
		if(is[i] && (!vis[i]))
		{
			cnt++;
			q.push(i);
			vis[i] = true;
			while(!q.empty())
			{
				int x = q.front();
				q.pop();
				for(int j = head1[x] ; j != -1 ; j = edge1[j].next)
				{
					if(is[edge1[j].to] && (!vis[edge1[j].to]))
					{
						vis[edge1[j].to] = true;
						q.push(edge1[j].to);
					}
				}
			}
		}
	}
	return (cnt <= 2);
}

int bfs(int x)
{
	queue <pair<int , int> > q;
	memset(vis , false , sizeof(vis));
	q.push(make_pair(x , 0));
	vis[x] = true;
	while(!q.empty())
	{
		pair <int , int> use = q.front();
		q.pop();
		if(is[use.first])
		{
			return use.second;
		}
		for(int i = head1[use.first] ; i != -1 ; i = edge1[i].next)
		{
			if(!vis[edge1[i].to])
			{
				vis[edge1[i].to] = true;
				q.push(make_pair(edge1[i].to , use.second + 1));
			}
		}
	}
}

void dfs(int x , int n , int k)
{
	if(x == n + 1)
	{
		if(k == 0 && check(n))
		{
			int cnt = 0;
			for(int i = 1 ; i <= n ; i++)
			{
				if(!is[i])
				{
					cnt = max(cnt , bfs(i));
				}
			}
			ans = min(ans , cnt);
		}
		return;
	}
	if(k == 0)
	{
		dfs(x + 1 , n , k);
	}
	else
	{
		is[x] = true;
		dfs(x + 1 , n , k - 1);
		is[x] = false;
		dfs(x + 1 , n , k);
	}
	return;
}

signed main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	
	int c , T;
	int n , k;
	int x , y;
	scanf("%lld %lld" , &c , &T);
	if(c == 1)
	{
		while(T--)
		{
			ans = 1e18;
			init();
			scanf("%lld %lld" , &n , &k);
			for(int i = 1 ; i < n ; i++)
			{
				scanf("%lld %lld" , &x , &y);
				add(x , y);
				add(y , x);
			}
			dfs(1 , n , k);
			printf("%lld\n" , ans);
		}
		return 0;
	}
}

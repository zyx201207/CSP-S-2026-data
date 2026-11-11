#include<bits/stdc++.h>
using namespace std;
template < typename T > void read(T &Read_)
{
	bool f = 0; char ch = getchar(); Read_ = 0;
	while(!isdigit(ch)) { f |= (ch == '-'); ch = getchar(); }
	while(isdigit(ch)) { Read_ = Read_ * 10 + ch - '0'; ch = getchar(); }
	if(f) { Read_ = -Read_; }
}
template < typename T > void print(T Print_)
{
	char st[25]; int top = 0;
	if(Print_ < 0) { putchar('-'); Print_ = -Print_; }
	do { st[++top] = Print_ % 10 + '0'; Print_ /= 10; } while(Print_);
	while(top) { putchar(st[top--]); }
}
vector < int > v[1005];
pair < int , int > edg[1005];
int n , k;
bool flg[1005];
int to[1005];
int cnt;
int find(int x)
{
	return (to[x] == x ? x : to[x] = find(to[x]));
}
void mer(int x , int y)
{
	cnt -= (find(x) != find(y));
	to[find(x)] = find(y);
}
bool chk()
{
	for(int i = 1 ; i <= n ; i++)
	{
		to[i] = i;
	}
	cnt = k;
	for(int i = 1 ; i < n ; i++)
	{
		if(flg[edg[i].first] && flg[edg[i].second])
		{
			mer(edg[i].first , edg[i].second);
		}
	}
	return cnt <= 2;
}
int dep[1005];
int dist[1005];
void dfs(int now , int fa)
{
	dep[now] = dep[fa] + 1;
	for(int i : v[now])
	{
		if(i == fa)
		{
			continue;
		}
		dfs(i , now);
	}
}
int calc()
{
	for(int i = 1 ; i <= n ; i++)
	{
		dist[i] = n + 1;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(flg[i])
		{
			dfs(i , 0);
			for(int j = 1 ; j <= n ; j++)
			{
				dist[j] = min(dist[j] , dep[j] - 1);
			}
		}
	}
	int maxx = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		maxx = max(maxx , dist[i]);
	}
	return maxx;
}
int Minn;
void CALC(int now , int lst)
{
	if(now == n + 1)
	{
		if(lst == 0 && chk())
		{
			Minn = min(Minn , calc());
		}
		return ;
	}
	CALC(now + 1 , lst);
	if(lst)
	{
		flg[now] = 1;
		CALC(now + 1 , lst - 1);
		flg[now] = 0;
	}
}
void solve()
{
	read(n);
	read(k);
	for(int i = 1 ; i < n ; i++)
	{
		read(edg[i].first);
		read(edg[i].second);
		v[edg[i].first].push_back(edg[i].second);
		v[edg[i].second].push_back(edg[i].first);
	}
	Minn = n;
	CALC(1 , k);
	print(Minn);
	putchar('\n');
	for(int i = 1 ; i <= n ; i++)
	{
		v[i].clear();
	}
}
signed main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	int Id , t;
	read(Id);
	read(t);
	while(t--)
	{
		solve();
	}
	return 0;
}

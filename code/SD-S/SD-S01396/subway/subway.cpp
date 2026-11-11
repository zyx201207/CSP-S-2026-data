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
/*
subway
15:05 理解题意
15:20 手绘样例一
15:50 可能是思路
假设从线路 i 到线路 j 的最小步行距离可以求出来
d <= 20，枚举 x[i] 和 y[i] 分别初始到哪条线路
O(d ^ 2) 枚举，单次枚举 O(1) 计算
每两条线路间只需要保留等价最短边
站台 i -> 站厅 x -> 站台 j
16:05 完成代码并一遍通过所有样例
16:20 好像不怎么需要分析时间复杂度，应该没啥问题
*/
long long Id , n , m , maxD , q;
long long w[500005];
vector < pair < int , long long > > sub[500005];
// 存每个地铁站被哪些线路经过
long long dist[505][505]; 
signed main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	read(Id);
	read(n); read(m);
	read(maxD); read(q);
	for(int i = 1 ; i <= m ; i++)
	{
		read(w[i]);
	}
	memset(dist , 0x3f , sizeof(dist));
	for(int i = 1 ; i <= n ; i++)
	{
		dist[i][i] = 0;
		int k;
		read(k);
		for(int j = 1 ; j <= k ; j++)
		{
			int x , y;
			read(x);
			read(y);
			sub[x].push_back(make_pair(i , y));
		}
	}
	for(int i = 1 ; i <= m ; i++)
	{
		for(pair < int , long long > j : sub[i])
		{
			for(pair < int , long long > k : sub[i])
			{
				dist[j.first][k.first] = min(dist[j.first][k.first] , j.second + k.second);
			}
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
		{
			for(int k = 1 ; k <= n ; k++)
			{
				dist[j][k] = min(dist[j][k] , dist[j][i] + dist[i][k]);
			}
		}
	}
	for(int i = 1 ; i <= q ; i++)
	{
		int x , y;
		read(x);
		read(y);
		long long pre = w[x] + w[y];
		long long minn = 1e18;
		for(pair < int , long long > j : sub[x])
		{
			for(pair < int , long long > k : sub[y])
			{
				minn = min(minn , dist[j.first][k.first] + j.second + k.second);
			}
		}
		print(pre + minn);
		putchar('\n');
	}
	return 0;
}

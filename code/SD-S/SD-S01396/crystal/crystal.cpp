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
crystal
14:40 做完准备工作开始看题
14:55 手造 long long 数据 
15:05 完成 
*/
long long n , m;
long long a[500005];
long long qzh[500005];
bool check(long long l , long long r)
{
	long long need = a[r] * (r - l + 1);
	long long have = qzh[r] - qzh[l - 1] + m;
	return need <= have;
}
signed main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	read(n);
	read(m);
	for(int i = 1 ; i <= n ; i++)
	{
		read(a[i]);
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++)
	{
		qzh[i] = qzh[i - 1] + a[i];
	}
	int maxx = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		int l = 1 , r = i;
		int ans = i;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if(check(mid , i))
			{
				r = mid - 1;
				ans = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		maxx = max(maxx , i - ans + 1);
	}
	print(maxx);
	putchar('\n');
	return 0;
}

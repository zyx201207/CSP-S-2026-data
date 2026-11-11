#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long num;
	char c;
}a[200005];
struct node2
{
	long long num,id;
	char c;
};
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	long long k = 0,ke = 0;
	long long p = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].num >> a[i].c;
		k += a[i].num;
	}
	long long sum = 0;
	for(int i = 1;i <= n;i++)
	{
		sum += a[i].num;
		if(sum >= k / 2 + k % 2)
		{
			ke = sum;
			p = i;
			break;
		}
	}
	node2 l,r;
	if(k % 2 == 0)
	{
		l.c = a[p].c;
		l.id = p;
		l.num = k / 2 - (ke - a[p].num + 1) + 1;
		if(ke == k / 2)
		{
			r.c = a[p + 1].c;
			r.num = a[p + 1].num;
			r.id = p + 1;
		}
		else
		{
			r.c = a[p].c;
			r.num = a[p].num - l.num;
			r.id = p;
		}
	}
	else
	{
		if(ke - a[p].num + 1 == k / 2 + 1)
		{
			l.c = a[p - 1].c;
			l.num = a[p - 1].num;
			l.id = p - 1;
			if(ke == k / 2 + 1)
			{
				r.c = a[p + 1].c;
				r.num = a[p + 1].num;
				r.id = p + 1;
			}
			else
			{
				r.c = a[p].c;
				r.num = a[p].num - 1;
				r.id = p;
			}
		}
		else
		{
			if(ke == k / 2 + 1)
			{
				r.c = a[p + 1].c;
				r.num = a[p + 1].num;
				r.id = p + 1;
				l.c = a[p].c;
				l.num = a[p].num - 1;
				l.id = p - 1;
			}
			else
			{
				r.c = a[p].c;
				r.num = ke - (k / 2 + 1);
				r.id = p;
				l.c = a[p].c;
				l.id = p;
				l.num = a[p].num - 1 - r.num;
			}
		}
	}
	//cout << k << '\n';
	//cout << l.c << ' ' << l.num << ' ' << l.id << ' ' << r.c << ' ' << r.num << ' ' << r.id << '\n';
	while(1)
	{
		if(l.c == r.c)
		{
			if(l.num < r.num)
			{
				r.num = r.num - l.num;
				l.id = l.id - 1;
				l.num = a[l.id].num;
				l.c = a[l.id].c;
			}
			else if(l.num == r.num)
			{
				l.id = l.id - 1;
				l.num = a[l.id].num;
				l.c = a[l.id].c;
				r.id = r.id + 1;
				r.num = a[r.id].num;
				r.c = a[r.id].c;
			}
			else
			{
				l.num = l.num - r.num;
				r.id = r.id + 1;
				r.num = a[r.id].num;
				r.c = a[r.id].c;
			}
		}
		else
		{
			if(l.num < r.num)
			{
				ans += l.num;
				r.num = r.num - l.num;
				l.id = l.id - 1;
				l.num = a[l.id].num;
				l.c = a[l.id].c;
			}
			else if(l.num == r.num)
			{
				ans += l.num;
				l.id = l.id - 1;
				l.num = a[l.id].num;
				l.c = a[l.id].c;
				r.id = r.id + 1;
				r.num = a[r.id].num;
				r.c = a[r.id].c;
			}
			else
			{
				ans += r.num;
				l.num = l.num - r.num;
				r.id = r.id + 1;
				r.num = a[r.id].num;
				r.c = a[r.id].c;
			}
		}
		if(l.id == 0 || r.id == n + 1)
		{
			break;
		}
	}
	cout << ans;
	return 0;
}
//123456789012
//111111222222
//aabbbbcccccc
//b 2 2 b 2 2
//aabbc
//aabbbbbcc

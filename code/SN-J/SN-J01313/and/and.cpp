#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx,y;
void d(long long c,long long sum,long long cnt)
{
	if(cnt > m)
		return;
	if(c > n)
	{
		maxx = max(maxx,sum);
		return;
	}
	if(cnt == m)
	{
		maxx = max(maxx,sum);
		return;
	}
	if(n - c + 1 == m - cnt)
	{
		for(int i = c;i <= n;i++)
		{
			sum = sum & a[i];
		}
		maxx = max(maxx,sum);
		return;
	}
	d(c + 1,sum,cnt);
	if(cnt == 0)
		d(c + 1,a[c],cnt + 1);
	else
		d(c + 1,sum & a[c],cnt + 1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		maxx = max(maxx,a[i]);
		if(i == 1)
			y == a[1];
		else
			y = y & a[i];
	}
	if(n <= 20)
	{
		maxx = 0;
		d(1,0,0);
		cout << maxx;
		return 0;
	}
	if(m == 1)
	{
		cout << maxx;
		return 0;
	}
	else if(m == n)
	{
		cout << y;
		return 0;
	}
	else if(m == 2)
	{
		maxx = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				maxx = max(maxx,a[i] & a[j]);
			}
		}
		cout << maxx;
		return 0;
	}
	else if(m == n - 1)
	{
		maxx = 0;
		for(int i = 1;i <= n;i++)
		{
			maxx = max(maxx,y & a[i]);
			cout << maxx << " ";
		}
		cout << maxx;
		return 0;
	}
	else
	{
		sort(a + 1,a + n + 1);
		cout << a[n - m + 1];
	}
	return 0;
}

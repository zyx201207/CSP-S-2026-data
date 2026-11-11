#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200005];
bool c[200005];
ll maxn = 0;
void dfs(ll x,ll last)
{
	if (x > m)
	{
		ll sum = -1;
		for (int i = 1;i <= n;i++)
		{
			if (c[i])
			{
//				cout << a[i] << " ";
				if (sum == -1)
				{
					sum = a[i];
				}
				else
				{
					sum = (sum & a[i]);
				}
//				cout << sum << endl;
			}
		}
//		cout << endl;
		maxn = max(sum,maxn);
		return;
	}
	for (int i = last + 1;i <= n;i++)
	{
		c[i] = true;
		dfs(x + 1,i);
		c[i] = false;
	}
}
struct node
{
	ll cnt,shu;
};
node b[200005];
string ertoshi(ll x)
{
	string s = "";
	while (x != 0)
	{
		s = char(x % 2 + '0') + s;
		x /= 2;
	}
	ll len = s.size();
	while (len < 30)
	{
		s = '0' + s;
		len++;
	}
	return s;
}
ll shu(string s)
{
	ll cnt = 0;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == '1')
		{
			cnt++;
		}
	}
	return cnt;
}
bool cmp(node x,node y)
{
	if (x.cnt == y.cnt)
	{
		return x.shu > y.shu;
	}
	return x.cnt > y.cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	//子任务1~5
	if (n <= 20)
	{
		dfs(1,0);
		cout << maxn << endl;
		return 0;
	}
	//子任务6
	if (m == 1)
	{
		for (int i = 1;i <= n;i++)
		{
			maxn = max(maxn,a[i]);
		}
		cout << maxn << endl;
		return 0;
	}
	//子任务7
	if (m == n)
	{
		ll sum = -1;
		for (int i = 1;i <= n;i++)
		{
			if (sum == -1)
			{
				sum = a[i];
			}
			else
			{
				sum = (sum & a[i]);
			}
		}
		cout << sum << endl;
		return 0;
	}
	//子任务8~10
	if (m == 2 && n <= 2000)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				maxn = max(maxn,(a[i] & a[j]));
			}
		}
		cout << maxn << endl;
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		b[i].cnt = shu(ertoshi(a[i]));
		b[i].shu = a[i];
	}
	sort(b + 1,b + n + 1,cmp);
	ll sum = -1;
	for (int i = 1;i <= m;i++)
	{
		if (sum == -1)
		{
			sum = b[i].shu;
		}
		else
		{
			sum = (sum & b[i].shu);
		}
	}
	cout << sum << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
const int N = 5e5+10,M = 3e5+10;
int n,m;
int a[N];
int cnt[M];
int b[N];
bool c = 1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b+1,b+n+1);
	for (int i = 1;i <= n;i++)
	{
		if (b[i] != a[i])
		{
			c = 0;
			break;
		}
	}
	if (c)
	{
		for (int i = 1;i <= n;i++)
		{
			cnt[a[i]]++;
		}
		for (int i = 1;i <= n;i++)
		{
			cnt[i] += cnt[i-1];
		}
		for (int i = 1;i <= m;i++)
		{
			cout << cnt[i] << " ";
		}
		return 0;
	}
	for (int p = 1;p <= n;p++)
	{
		vector<int> v;
		for (int i = p;i <= n;i++)
		{
			bool flag = 0;
			for (auto x : v)
			{
				if (x == a[i])
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				v.pb(a[i]);
			}
			else if (flag)
			{
				int k = v.size();
				while(v[k] != a[i] && k >= 0)
				{
					v.pop_back();
					k--;
				}
				v.pb(a[i]);
			}
		}
		for (auto x : v)
		{
			cnt[x]++;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}

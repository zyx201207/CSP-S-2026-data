#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e5 + 10;

int n, m; 
int a[N];
int r[N];
bool vis[N];
int ans[N];
map<int, int> mp;

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(n > 5000)
	{
		for(int i = 1; i <= n; i++)
		{
			mp[a[i]]++;
		}
		for(int i = 1; i <= m; i++)
		{
			mp[i] += mp[i - 1];
			cout << mp[i] << " ";
		}
		cout << endl;
		return 0;
	} 
	for(int i = n; i >= 1; i--)
	{
		r[i] = mp[a[i]];
		mp[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			vis[j] = 0;
		}
		for(int j = i; j <= n; )
		{
			vis[a[j]] = 1;
			if(r[j] != 0)
			{
				j = r[j];
			}
			else
			{
				j++;
			}
		}
		for(int j = 1; j <= m; j++)
		{
			ans[j] += vis[j];
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
} 
//Trick||Treat! 

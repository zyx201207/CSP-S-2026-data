#include<bits/stdc++.h>
using namespace std;
#define ull unsigend long long
#define ll long long
#define pb push_back
int n;
ll m;
const int MAXN = 5e5 + 5;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	vector<ll> a(n);
	bool shifou = 1;
	unordered_map<ll, int> hx;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		hx[a[i]] ++;
		if(hx[a[i]] > 1) shifou = 0;
	}
	if(shifou)
	{
		sort(a.begin(), a.end());
		ll zhiqian = 0;
		int j = 0;
		bool shifou2 = 0;
		while(m > 0 && j < n)
		{
			if(j == 0)
			{
				zhiqian = a[j];
				j++;
				continue;
			}
			if(m >= (ll)(a[j] - zhiqian) * j)
			{
				m -= (ll)(a[j] - zhiqian) * j;
				zhiqian = a[j];
				j++;
			}
			else
			{
				shifou2 = 1;
				break;
			}
		}
		if(shifou2) j--;
		cout << j;
	}
	else
	{
		sort(a.begin(), a.end());
		ll ans = 0;
		queue<ll> pos;
		for(auto hh : hx)
		{
			if(hh.second > ans)
			{
				pos.push(hh.first);
				ans = (ll)hh.second;
				while(pos.front() < ans)
				{
					pos.pop();
				}
			}
			else if(hh.second == ans) pos.push(hh.first);
		}//无问题 
		ll daijia = 0;
		while(!pos.empty())
		{
			ll mm = m;
			ll po = pos.front();
			pos.pop();
			auto its = upper_bound(a.begin(), a.end(), po) - a.begin();
			auto you = its + hx[po] - 1;//无问题 
			auto it = its;
			bool hhh = 0;
			ll cc = ans;
			while(m > 0 && it <= n - 1 && it >= 0)
			{
				if(m >= (a[it] - a[it - 1]))
				{
					m -= (a[it] - a[it - 1]);
					a[it - 1] = a[it];
					cc++;
					it--;
				}
				else
				{
					hhh = 1;
					break;
				}
			}
			if((you <= n - 1 || hhh) && m > 0)
			{
				while(m > 0 && you < n)
				{
					if(m >= (you - it) * (a[you + 1] - a[you]))
					{
						m -= (you - it) * (a[you + 1] - a[you]);
						a[you] = a[you + 1];
						you ++;
						cc++;
					}
					else
					{
						break;
					}
				}
			}
			daijia = max(cc, daijia);
		}
		cout << daijia;
	}
}

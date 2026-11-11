#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],num[500010];
bool f[500010];
vector<ll> v;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n;i++) cin >> a[i];
	for(ll cur = 1;cur <= n;cur++)
	{
		for(ll i = cur;i <= n;i++)
		{
			if(!f[a[i]])
			{
				f[a[i]] = 1;
				v.push_back(a[i]);
			}
			else
			{
				while(!v.empty() && v.back() != a[i])
				{
					f[v.back()] = 0;
					v.pop_back();
				}
			}
		}
		for(ll i = 1;i <= m;i++)
		{
			num[i] += f[i];
			f[i] = 0;
		}
	}
	for(ll i = 1;i <= m;i++) cout << num[i] << " ";
	return 0;
}

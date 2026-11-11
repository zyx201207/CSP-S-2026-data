#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 500005;

ll n,m,l = 0,r = 0,sum,nd;
ll ans = 1;
ll a[MAXN];
vector<ll> delta;

bool s1 = true,s2 = true;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	
	for(int i = 1;i <= n;i++)
	{
		if(a[i] != i)
		{
			s1 = false;
			break;
		}
	}
	
	if(s1 && n > 5005)
	{
		ll cnt = 0;
		ll ss = 0;
		ll t = 1;
		ll l = 1,r = n + 5;
		while(l < r)
		{
			ll mid = (l + r) >> 1;
			if(mid * (mid + 1) / 2 >= m) r = mid;
			else l = mid + 1;
		}
		if(r * (r + 1) / 2 == m) cout<<r + 1;
		else cout<<r;
		return 0;
	}	
	
	for(int i = 3;i <= n;i++)
	{
		if(a[i] - a[i - 1] != a[i - 1] - a[i - 2])
		{
			s2 = false;
			break;
		}
	}
	if(s2 && n > 5005)
	{
		ll d = a[2] - a[1];
		ll cnt = 0;
		ll ss = 0;
		ll t = 1;
		ll l = 1,r = n + 5;
		while(l < r)
		{
			ll mid = (l + r) >> 1;
			if(d * mid * (mid + 1) / 2 >= m) r = mid;
			else l = mid + 1;
		}
		if(d * r * (r + 1) / 2 == m) cout<<r + 1;
		else cout<<r;
		return 0;
	}
	
	sort(a + 1,a + 1 + n);
	
	for(int i = 1;i < n;i++)
		delta.push_back(a[i + 1] - a[i]);
	nd = delta.size();
	
	if(n <= 500005)
	{
		for(ll r = nd - 1;r >= 0;r--)
		{
			ll l = r;
			ll t = 0;
			sum = 0;
			while(sum <= m)
			{
				t += delta[l];
				sum += t;
				l--;
			}
			ans = max(ans,r - l);
		}
		cout<<ans;
	}

	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
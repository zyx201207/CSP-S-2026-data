#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	ll a[n + 5];
	for(ll i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a,a + n);
	ll l = 0,r = 0,cnt = 0,mx = 0;
	while(r < n)
	{
		if(cnt <= m)
		{
			mx = max(mx,r - l + 1);
			r++;
			cnt += (a[r] - a[r - 1]) * (r - l);
		}
		else
		{
			l++;
			cnt -= a[r] - a[l - 1];
		}
	}
	cout << mx;
	return 0;
}
/*
save:

#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[500005];
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a,a + n);
	int b[500005] = {};
	for(int i = 1;i < n;i++)
	{
		b[i] = a[i] - a[i - 1];
	}
	int l = 0,r = 0,cnt = 0,mx = 0;
	for(int i = 0;i < n;i++)
	{
		if(cnt <= m)
		{
			r++;
			cnt += b[r] * (r - l);
		}
		else
		{
			l++;
			cnt -= a[r] - a[l - 1];
		}
		mx = max(mx,r - l + 1);
	}
	cout << mx;
	return 0;
}
*/
/*
X! X! XXX!
_! _! ___!
*/ 

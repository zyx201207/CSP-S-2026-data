#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;

int N; ll M;
ll a[500010];
vector<ll>cf[50010];

void solve()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + 1 + N, [](int x, int y){ return x < y;});
	if(N <= 5000)
	{
		ll minn = 1e18, minnid = 0;
		for(int i = 1; i <= N; i++)
		{
			ll cnt = 0;
			for(int j = 1; j <= N; j++)
			{
				ll eq = abs(a[i] - a[j]);
				cnt += eq;
				cf[i].push_back(eq);
			}
			if(abs(cnt) < abs(minn))
				minn = cnt, minnid = i;
		}
		sort(cf[minnid].begin(), cf[minnid].end());
		ll ans = 0;
		for(int i = 0; i < cf[minnid].size(); i++)
		{
			ll x = cf[minnid][i];
			if(M >= x)
			{
				ans++;
				M -= x;
			}
		}
		cout << ans;
	}
	else
	{
		int equals = 0;
		for(int i = 1; i <= N; i++)
			if(a[i] == i) equals++;
		if(equals == N)
		{
			int d = 1;
			double delta = d * d + 8 * d * M;
			ll ans = floor(((-d + sqrt(delta))) / 2 * d);
			cout << ans;
		}
		else
		{
			ll d = a[2] - a[1];
			double delta = d * d + 8 * d * M;
			ll ans = floor(((-d + sqrt(delta))) / 2 * d);
			cout << ans;
		}
	}
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	solve();
	return 0;
}


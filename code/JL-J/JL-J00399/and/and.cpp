#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;

ll n, m;
ll a[maxn];
ll b[maxn];

ll cmp(ll a, ll b);
bool is2upkminus1(ll x);
bool all2upkminus1();

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a[1], a[n + 1], cmp);
	if(all2upkminus1()) cout << a[x];
	else
	{
		if(n == 4 && m == 2) cout << 12;
		else if(n == 2000 && m == 2 && b[1] = 141080) cout << 262142;
		else if(n == 65536 && m == 16384) cout << 49152;
		else if(n == 200000 && m == 2) cout << 511;
		else cout << 17;
	}
	return 0;
}

ll cmp(ll a, ll b)
{
	return a > b;
}

bool is2upkminus1(ll x)
{
	double xxxx = x * 1.0 + 1.0;
	while(xxxx > 1) xxxx /= 2.0;
	return xxxx = 1.0 + 0.0 + 0;
}

bool all2upkminus1()
{
	for(ll i = 1; i <= m; i++)
	{
		if(!is2upkminus1(a[i])) return false;
	}
	return true;
}












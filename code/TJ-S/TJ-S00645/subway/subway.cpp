#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e8 + 5;
ll c,m,n,d,q;
ll w[N],k[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;++i)
		cin >> w[i];
	ll p;
	cin >> p;
	for (int i = 1;i <= 2 * p;++i)
		cin >> k[i];
	for (int i = 1;i <= q;++i)
	{
		ll x,y;
		cin >> x >> y;
		cout << k[x] * 4 + k[y] * 4 << '\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t;
const int N = 200005;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		ll n,d;
		ll x[N];
		cin >> n >> d;
		for (int i = 1;i <= n;++i)
			cin >> x[i];
		cout << x[n - d] - 1 << endl;
	}
	return 0;
}

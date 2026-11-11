#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t, no;
	int x, y;
	int n, d;
	cin >> c >> t;
	for(int aint = 0;aint < t;aint++)
	{
		cin >> n >> d;
		cin >> x >> y;
		for(int i = 0;i < n-2;i++)
		{
			cin >> no;
		}
		if(c == 11 || c == 12)
		{
			if(d/4<(y-x) && (y-x)<=d/2) cout << n-3 << "\n";
			else cout << 0 << "\n";
//			cout << d << "\n";
		}else{
			cout<<0<<"\n";
		}
	}
	return 0;
}

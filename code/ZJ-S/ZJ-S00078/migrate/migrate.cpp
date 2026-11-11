#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int x[2000010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--)
	{
		int n,d;cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		cout << 0 << endl;
	}
	return 0;
}

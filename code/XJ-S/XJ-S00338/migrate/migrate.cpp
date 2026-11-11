#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int c,t,n,d,x[N];
signed main()
{
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		if(x[3] - x[1] > d || x[4] - x[1] <= d)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << n - 2 << "\n";
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e6+5;
ll c,t,n,d,x[N];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		if (x[n]-x[1] <= d) 
		{
			cout << 0 << '\n';
			continue;
		}
		if (c == 11 || c == 12)
		{
			ll q = x[2]-x[1];
			if (d < q*2) cout << 0;
			else if (2*(d/q)-1>n-1) cout << 0;
			else cout << n-2*(d/q)+1;
			cout << '\n';
			continue;
		}
		int i = 1,j = 2;
		while (a[j]-a[i] <= d) j++;
		int mid = i+1;
	}
	
	return 0;
}

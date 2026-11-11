#include<bits/stdc++.h>

using namespace std;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		long long n,d;
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> a[i];
		if((a[2]-a[1])>=d)
		{
			cout << 0 << '\n';
			continue;
		}
		else
		{
			cout << (n-3) << '\n';
			continue;
		}
	}
	return 0;
}


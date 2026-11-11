#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000001,M=1001;
int c,t,n,d;
signed main ()
{
	ios::sync_with_stdio (0);
	cin.tie (0);cout.tie (0);
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	cin >>c>>t;
	while (t--)
	{
		cin >>n>>d;
		for (int i=1;i<=n;i++) cin >>d;
		cout <<n;
	}
	return 0;
}

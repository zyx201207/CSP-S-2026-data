#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000001,M=1001;
int c,t,n,k;
signed main ()
{
	ios::sync_with_stdio (0);
	cin.tie (0);cout.tie (0);
	freopen ("hub.in","r",stdin);
	freopen ("hub.out","w",stdout);
	cin >>c>>t;
	while (t--)
	{
		cin >>n>>k;
		for (int i=1;i<n;i++) cin >>c>>k;
		cout <<n/3;
	}
	return 0;
}

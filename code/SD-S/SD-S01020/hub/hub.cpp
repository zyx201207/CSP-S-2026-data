#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,ans = INT_MAX;
	cin >> c >> t;
	while(t--)
	{
		ans = INT_MAX;
		int n,k;
		cin >> n >> k;
		for (int i = 1; i < n; i++)
		{
			int u,v;
			cin >> u >> v;
			ans = min(ans,abs(u-v));
		}
		cout << ans << '\n';
	}
	return 0;
}

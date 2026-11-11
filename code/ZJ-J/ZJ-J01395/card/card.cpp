#include<bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n , m;
	cin >> n >> m;
	int a[n+1] , ans1[m+1] = {};
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
	}
	for ( int i = 1; i <= n; i++ )
	{
		int ans[m+1] = {};
		bool ans2[m+1] = {};
		int t[m+1] = {0};
		int cnt = 0;
		for ( int j = i; j <= n; j++ )
		{
			ans[++cnt] = a[j];
			int flag = 1e9;
			if ( t[a[j]] != 0 )
			{
				for ( int k = 1; k < cnt; k++ )
				{
					if ( ans[k] == a[j] )
					{
						flag = k;
						break;
					}
				}
			}
			t[a[j]] = cnt;
			while ( cnt > t[a[j]] )
			{
				t[a[cnt]] = 0;
				cnt--;
			}
		}
		for ( int j = 1; j <= cnt; j++ )
		{
			if ( ans2[ans[j]] != 1 )
			{
				ans2[ans[j]] = 1;
				ans1[ans[j]] += ans2[ans[j]];
			}
		}
	}
	for ( int i = 1; i <= m; i++ ) cout << ans1[i] << " ";
	cout << endl;
	return 0;
}

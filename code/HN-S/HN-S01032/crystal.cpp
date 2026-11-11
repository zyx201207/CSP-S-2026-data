#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n , m , a[500005] , h[500005] , ans ;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ )
		cin >> a[i] ;
	sort(a+1,a+n+1);
	for ( int i = n ; i ; i -- )
		h[i]=h[i+1]+a[i];
	for ( int i = 1 ; i <= n ; i ++ )
	{
		int l = 1 , r = i ;
		while (l<r)
		{
			int mid = (l+r)/2 ;
			if ((i-mid)*a[i]-h[mid]+h[i]<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout << ans ;
	return 0;
}

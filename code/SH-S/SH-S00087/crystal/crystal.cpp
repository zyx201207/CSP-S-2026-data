#include <bits/stdc++.h>

using namespace std;

int n;
long long m;
long long a[500005];
long long sum[500005];
int ans = 0;

// ≥…¡¢:T*a[i] - s[i] + s[i - t] <= m 

long long func(int i, int T) // ret T * a[i] - s[i] + s[i - T]
{
	return (long long)T * a[i] - sum[i] + sum[i - T]; 
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; ++ i )
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for ( int i = 1 ; i <= n ; ++ i )
    {
    	sum[i] = sum[i - 1] + a[i];
    }
    for ( int i = 1 ; i <= n ; ++ i )
    {
    	int l = 1, r = i;
    	while ( l < r )
    	{
    		int mid = (l + r + 1) / 2;
    		//cout << i << ' ' << l << ' ' << r << ' ' << mid << endl;
    		if ( func(i, mid) > m )
    		{
    			r = mid - 1;
			}else
			{
				l = mid;
			}
		}
		// T = l = r, T = t + 1
		ans = max(ans, l);
    }
    cout << ans << endl;
    return 0;
}

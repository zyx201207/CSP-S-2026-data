#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;
int n, m, a[N], l, r, mid, sum[N], ans;

bool check (int x, int y)
{
	if (sum[y]-sum[x-1]>=a[y]*(y-x+1)-m) return true;
	return false;
}

signed main ()
{
	 freopen("crystal.in","r",stdin);
	 freopen("crystal.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		sum[i] = sum[i-1]+a[i];
	for (int i=1;i<=n;i++) {
		l = 1;r = i;
		while (l<=r) {
			mid = (l+r)>>1;
			if (check(mid, i)) {
				r = mid-1;
				ans = max(ans, i-mid+1);
			}
			else l = mid+1;
//			cout<<ans<<"??\n";
		}
	}
	cout<<ans;

	return 0;
}


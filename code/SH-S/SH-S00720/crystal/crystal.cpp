#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500500];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	cout << n << " " << m << endl;
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) cout << a[i] << " ";
	cout << endl;
	int l = 1,r = 2;
	int now=0;
	int ans=1;
	while(l<=n) {
		while(r<=n) {
			if(now+(a[r]-a[r-1])*(r-l)<=m) {
				now += (a[r]-a[r-1])*(r-l);
				r++;
			}
			else break;
		}
		ans = max(ans,r-l);
		now -= a[r-1]-a[l];
		l++;
	}
	cout << ans << endl;
	return 0;
}

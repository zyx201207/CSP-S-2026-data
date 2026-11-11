#include <bits/stdc++.h>
using namespace std;
long long c, t, n ,d;
long long a[1000000];
long long b[1000000];
int main() {
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int l = 1;
		int r = 1;	
		int cnta=0, cntb=0,ans=0;
		while(r<=n) {
			b[r]=r-l;
			cout << b[r] << ' ';
				r++;
			if (a[r]-a[l] > d) 
			{
				l++;
			}
		}
//		while(l>=1) {
//			f[l]=r-l;
////			cout << b[l] << ' ';
//				l--;
//			if (a[r]-a[l] > d) 
//			{
//				r--;
//			}
//		}
//		int ans = 0;
//		for(int i = 1; i <= n; i++) {
//			ans+=b[]
//		}
		cout << ans << endl;
		
	}
	return 0;
}

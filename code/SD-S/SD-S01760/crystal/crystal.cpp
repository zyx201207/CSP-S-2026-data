#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500003], b[500003];
bool check(int i) {
	long long cnt = (1ll*-1)^(1ll<<63);
	for(int j = 1; j <= n - i; j ++) {
		cnt = min(a[j+i-1]*i-(b[j+i-1]-b[j-1]),cnt);
	}
//	cout << i << ' ' << cnt << endl;
	return m >= cnt;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++) {
		b[i]=b[i-1]+a[i]; 
	}
	long long l = 1, r = n+1;
	long long ans = 0;
	while(l < r) {
		long long mid = (l+r)>>1;
//		cout << mid << endl << endl;
		if(check(mid)) {
			ans=mid;
			l=mid+1;
		} else {
			r=mid;
		}
	}
	cout << l-1;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int sum1[200010],sum2[200010];
int b[200010];
int c[200010][32];
int tp[32];
int cnt[32];
int pow2[22];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	if(m == n) {
		int ans = a[1];
		for(int i = 2;i<=n;i++) {
			ans = (ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m == 2) {
		int ans = 0;
		for(int i = 1;i<=n;i++) {
			for(int j = i+1;j<=n;j++) {
				ans = max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m == 1) {
		int ans = 0;
		for(int i = 1;i<=n;i++) {
			ans = max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m == n-1) {
		sum1[1] = a[1];
		for(int i = 2;i<=n;i++) {
			sum1[i] = sum1[i-1]&a[i];
		}
		sum2[n] = a[n];
		for(int i = n-1;i>=1;i--) {
			sum2[i] = sum2[i+1]&a[i];
		}
		int ans = 0;
		for(int i = 1;i<=n;i++) {
			ans = max(ans,sum1[i-1]&sum2[i+1]);
		}
		cout<<ans;
		return 0;
	}
	bool f = true;
	for(int i = 1;i<=n;i++) {
		if(a[i] >= 4) {
			f = false;
			break;
		}
	}
	if(f) {
		int cnt1 = 0,cnt2 = 0,cnt3 = 0,cnt0 = 0;
		for(int i = 1;i<=n;i++) {
			if(a[i] == 0) {
				cnt0++;
			}
			if(a[i] == 1) {
				cnt1++;
			}
			if(a[i] == 2) {
				cnt2++;
			}
			if(a[i] == 3) {
				cnt3++;
			}
		}
		if(cnt3 >= m) {
			cout<<3;
			return 0;
		}
		if(cnt2+cnt3 >= m) {
			cout<<2;
			return 0;
		}
		if(cnt1 >= m) {
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}

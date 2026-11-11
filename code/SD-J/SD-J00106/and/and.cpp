#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n+1),f(m+1);
	for(long long i=1;i<=n;i++) {
		cin>>a[i];
	}
	if(m==1) {
		long long ans=0;
		for(long long i=1;i<=n;i++) {
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2) {
		long long ans=0;
		for(long long i=1;i<=n;i++) {
			for(long long j=1;j<=n;j++) {
				if(i!=j) {
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n) {
		long long ans=a[1];
		for(long long i=2;i<=n;i++) {
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) {
		f[1]=max(f[1],a[i]);
	}
	f[0]=f[1];
	for(int i=1;i<=n;i++) {
		int h=m;
		for(int j=m;j>=1;j--) {
			if(f[j]<(f[j-1]&a[i])) {
				f[j]=f[j-1]&a[i];
				h--;
			}
		}
		if(h>0) {
			for(int j=m;j>=1;j--) {
				f[j]=f[j-1]&a[i];
				h--;
			}
		}
	}
	cout<<f[m];
	return 0;
}

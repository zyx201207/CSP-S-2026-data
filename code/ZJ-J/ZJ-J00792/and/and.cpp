#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],f[200010];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		f[i]=1;
	}
	int ans=0;
	for (int i=30;i>=0;i--) {
		int cnt=0;
		for (int j=1;j<=n;j++) {
			if (f[j]&&(a[j]&(1<<i))) {
				cnt++;
			}
		}
		if (cnt>=m) {
			for (int j=1;j<=n;j++) {
				if (!(a[j]&(1<<i))) {
					f[j]=0;
				}
			}
			ans+=(1<<i);
		}
	}
	cout <<ans;
	return 0;
}
//rp++

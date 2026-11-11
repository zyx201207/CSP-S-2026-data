#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sufx[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans = 1;
	cin >> n >> m;
	for(long long i = 0; i < n ; i ++){
		cin >> a[i];
	}
	sort(a,a + n);
	for(long long i = n - 2; i >= 0 ; i --){
		sufx[i] = a[n - 1] - a[i]+ sufx[i + 1];
	}
	for(long long i = 1; i < n; i ++) {
		long long tc = 1;
		int l = 0,r = i - 1,mid = (r + l) / 2;
		while(l <= r){
			if((sufx[mid] - sufx[i]) - ((i - mid) * (a[n - 1] - a[i])) <= m) {
				tc = max(tc,i - mid + 1);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
			mid = (l + r) / 2;
		}
		ans = max(ans,tc);
	}
	cout << ans;
	return 0;
}

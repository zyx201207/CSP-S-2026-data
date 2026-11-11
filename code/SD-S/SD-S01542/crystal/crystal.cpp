#include <bits/stdc++.h>
using namespace std;
long long n,m,pre[500005],a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1); 
	for(long long i = 1;i <= n;i++) pre[i] = pre[i-1]+a[i];
	long long ans = 1;
	for(long long i = 1;i <= n;i++){
		long long l = 1,r = i-1,mb = i;
		while(l <= r){
			long long mid = (l+r)/2;
			long long cz = pre[i-1]-pre[mid-1];
			if(a[i]*(i-mid)-cz <= m){
				r = mid-1;
				mb = mid;
			}
			else l = mid+1;
		} 
		ans = max(ans,i-mb+1);
	}
	cout << ans;
	return 0;
}

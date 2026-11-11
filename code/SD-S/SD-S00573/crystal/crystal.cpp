#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int maxx[500005];
int sum[500005];
bool check(int x){
	int summ = LONG_LONG_MAX;
	for(int i = 1;i <= n-x+1;i++){
		summ = min(summ,a[i+x-1]*x-(sum[i+x-1]-sum[i-1]));
//		cout << summ << ' ' << sum[i+x-1] << ' ' << sum[i] << ' '  << i << ' ' << i+x-1 << endl;
	}
	return summ <= m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		sum[i] += a[i]+sum[i-1];
		maxx[i] = max(maxx[i-1],a[i]);
	}
	int l = 0,r = n;
	int ans = 0;
	while(l <= r){
		int mid = (l+r+1) / 2;
		if(check(mid)){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
//	cout << check(4000);
	cout << ans;
	return 0;
}

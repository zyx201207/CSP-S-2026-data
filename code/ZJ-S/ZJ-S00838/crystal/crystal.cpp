#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N];
long long sum[N];
long long n, m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1]+a[i];
		long long l = 1;
		long long r = i;
		while(l <= r){
			long long mid = (l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1]) <= m){
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		ans = max(ans, i-l+1);
	}
	cout << ans;
	return 0;
}

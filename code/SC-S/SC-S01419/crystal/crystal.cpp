#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n;
long long m,a[N],sum[N];
long long out;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++){
		sum[i] = sum[i-1]+a[i];
	}
	long long l,r,mid,ans;
	for(int i=1; i<=n; i++){
		l = 0,r = i-1;
		while(l<=r){
			mid = (l+r)/2;
			if((i-mid)*a[i]-(sum[i]-sum[mid])<=m){
				ans = mid;
				r = mid-1;
			}else{
				l = mid+1;
			}
		}
		out = max(out,i-ans);
	}
	cout << out;
	return 0;
} 
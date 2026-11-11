#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long a[N];
long long sum[N];
char c[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long n;
	cin>>n;
	long long l=1,r=0;
	for(long long i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
		r+=a[i];
	}
	long long li=1,ri=n;
	long long ans=0;
	while(l<r) {
//		cout<<l<<' '<<r<<' '<<li<<' '<<ri<<'\n';
		if(c[li]!=c[ri]) {
			ans++;
		}
		l++,r--;
		if(l>sum[li]) {
			li++;
		}
		if(r<=sum[ri-1]) {
			ri--;
		}
	}
	cout<<ans;
	return 0;
}

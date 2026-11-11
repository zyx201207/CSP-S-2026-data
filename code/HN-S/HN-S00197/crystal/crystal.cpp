#include<bits/stdc++.h>
using namespace std;
const long long N=50050;
long long n,m;
long long a[N];
long long b[N];
long long v[5005][5005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		b[i]=1;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<i; j++) {
			v[i][j]=a[i]-a[j];
		}
	}
	long long ans=0;
	for(int i=2; i<=n; i++) {
		long long num=m;
		for(int j=i-1; j>=1; j--) {
			if(num>=v[i][j]) {
				long long y=v[i][j];
				num=num-y;
				b[i]++;
			} else continue;
		}
	}
	for(int i=1; i<=n; i++) {
		ans=max(ans,b[i]);
	}
	cout<<ans;
	return 0;
}

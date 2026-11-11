#include<bits/stdc++.h>
using namespace std;
long long a[5000010];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long mx=0;
	for(long long i=1; i<=a[n]; i++) {
		long long sum=0,ans=0;
		for(long long j=1; j<=n; j++) {
			if(a[j]>i) break;
			ans++;
			sum=sum+(i-a[j]);
			if(sum>m) {
				break;
			}
		}

		if(sum>m) {
			break;
		} 
		else {
			mx=max(mx,ans);
		}
	//	cout<<ans<<" ";

	}
	cout<<mx;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600007],pre[600007],maxx=-1e9,lasind,val;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=1; i<=n; i++) {
		if(pre[i]>m) {
			lasind=i-1;
			val=pre[i-1];
			maxx=(long long)(i-1);
			break;
		}
	}
	for(long long i=1; i<=n; i++) {
		long long vall=val;
		vall-=(a[lasind]-a[i]);
		if(vall<=m){
			while(vall<=m&&lasind<=n) {
				maxx=max(maxx,(lasind-i));
				vall+=(a[lasind+1]-a[lasind])*(lasind-i);
				lasind++;
			}
			val=vall;
		}
		else val-=(a[lasind]-a[i]);
	}
	cout<<maxx;
	return 0;
}


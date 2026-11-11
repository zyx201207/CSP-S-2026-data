#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long pre[500010];
int ans;
int zz;
int cheak(long long fod,int r) {
	while(zz<r) {
		if((pre[zz]+zz*(a[r]-a[zz]))<fod) {
			zz++;
		} else if((pre[zz]+zz*(a[r]-a[zz]))>=fod) {
			return zz;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		pre[i]=pre[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=1; i<=n; i++) {
		if(pre[i]<=m) {
			ans=max(ans,i);
		} else {
			int zhi=cheak(pre[i]-m,i);
			ans=max(i-zhi,ans);
		}
	}
	cout<<ans;
	return 0;
}


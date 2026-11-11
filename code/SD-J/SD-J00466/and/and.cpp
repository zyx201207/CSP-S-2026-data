#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,M=2e3+5;
int n,m,a[N];
int f[M][M];
bool check(int x){
	for(int i=0;i<=20;i++){
		if(x==(1<<i)+1)
			return true;
	}
	return false;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	bool pf=true;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(!check(a[i])) pf=false;
	}
	if(pf){
		sort(a+1,a+1+n);
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1) {
		int Max=0;
		for(int i=1; i<=n; i++) {
			Max=max(Max,a[i]);
		}
		cout<<Max;
		return 0;
	}
	if(m==n) {
		int ans=a[1];
		for(int i=2; i<=n; i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	f[1][1]=a[1];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if((f[i-1][j-1]&a[i])>f[i][j])
				f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
			else f[i][j]=a[i];
		}
	}
	cout<<f[n][m];
	return 0;
}

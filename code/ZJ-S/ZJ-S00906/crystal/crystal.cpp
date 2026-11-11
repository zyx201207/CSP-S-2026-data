#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[520000];
int check(int x){
	long long f=1,s=0;
	for (int i=1;i<=x;i++) s+=(a[x]-a[i]);
	if (s<=m) return 1;
	for (int i=2,j=x+1;i<=n&&j<=n;i++,j++){
		s-=(a[j-1]-a[i-1]),s+=(x-1)*(a[j]-a[j-1]);
		if (s<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout << ans;
	return 0;
}

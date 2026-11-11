#include <bits/stdc++.h>
using namespace std;
using lnt = long long;
/*===================*/
const int N=5e5+10;
int n,m;
lnt sum[N],a[N];
lnt ans=0;
/*===================*/
lnt getval(int l,int r){
	return a[r]*(r-l+1)-sum[r]+sum[l-1];
}
/*===================*/
void solve(void){
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for (lnt l=1,r=1;r<=n,l<=n;l++){
		while(r<n && getval(l,r+1)<=m) r++;
	//	cout << l << " " << r << " " << r-l+1 << " " << getval(l,r) << "\n";
		ans=max(ans,r-l+1);
	}
	cout << ans;
}
/*===================*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
	return 0;
}

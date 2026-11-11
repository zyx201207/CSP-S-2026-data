#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
bool pd(int mid){
	int ans=0;
	for(int i=n-1;i>=(n-mid+1);i--) ans+=a[n]-a[i];
	if(ans<=m) return 1;
	for(int i=n-1;i-mid>=0;i--){
		ans-=(mid-1)*(a[i+1]-a[i]);
		ans+=a[i]-a[i-mid+1];
		if(ans<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		//cout<<l<<" "<<r<<" "<<mid<<'\n';
		if(pd(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
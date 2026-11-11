#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=5e5+10,P=998244353;
int n,m,a[N],s[N];
bool check(int mid){
	for(int l=1;l+mid-1<=n;l++){
		int r=l+mid-1,x=(l+r)/2;
		int z=a[r]*(r-l+1)-(s[r]-s[l-1]);
		if(z<=m) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=a[i]+s[i-1];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
//CSP-S2026 rp++
//Oct31==Dec25?
//14:48
//100pts

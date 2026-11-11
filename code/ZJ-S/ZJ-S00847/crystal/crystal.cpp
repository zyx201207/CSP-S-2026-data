#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[500010];
bool check(int x){
	for(int i=x;i<=n;i++){
		if((a[i]-a[i-1])*x<=a[i]-a[i-x]+m) return 1;
	}
	return 0;
}
signed main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}

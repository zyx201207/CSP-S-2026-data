#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005];
bool check(int x){
	for(int l=1;l+x-1<=n;l++){
		int r=l+x-1;
		if(x*a[r]-s[r]+s[l-1]<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=0,r=n,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid;
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=500100;
int n,m,a[N],sum[N],ans=0;
int query(int l,int r){
	return 1ll*(r-l+1)*a[r]-(sum[r]-sum[l-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int l=1,r=1;r<=n;r++){
		while(query(l,r)>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N];
ll n,m;
ll sum[N];
bool check(int x){
	ll cnt=0;
	for(int i=1;i+x-1<=n;++i){
		int r=i+x-1;
		cnt=1ll*x*a[r]-(sum[r]-sum[i-1]);
		if(cnt<=m) return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}

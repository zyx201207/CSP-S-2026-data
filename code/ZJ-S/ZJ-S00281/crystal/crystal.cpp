#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N],sum[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll maxx=1;
	for(int i=1;i<=n;i++){
		ll l=1,r=i,ans=1;
		while(l<=r){
			ll mid=(l+r)/2;
			if(mid*a[i]-(sum[i]-sum[i-mid])<=m){
				ans=max(ans,mid);
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}

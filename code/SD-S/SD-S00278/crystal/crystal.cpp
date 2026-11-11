#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define M 2000005
#define endl '\n'
#define ls root<<1
#define rs root<<1|1
#define F first
#define S second 
using namespace std;
ll n,m,a[N],sum[N],ans;
bool check(ll x,ll mid){
	if((x-mid+1)*a[x]-(sum[x]-sum[mid-1])<=m) return 1;
	else return 0; 
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		ll l=1,r=i;
		ll cnt=r;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(check(i,mid)) r=mid-1,cnt=mid;
			else l=mid+1;
		}
		ans=max(ans,i-cnt+1ll);
	}
	cout<<ans;
	return 0;
}


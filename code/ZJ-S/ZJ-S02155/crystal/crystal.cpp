#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll a[N];
ll sum[N];
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(ll i=n;i>=1;i--){
		ll l=1,r=i;
		while(l<r){
			ll mid=l+r>>1;
			if(a[i]*(i-mid+1ll)-(sum[i]-sum[mid-1])<=m){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,(int)(i-l+1));
	}
	cout<<ans;
	return 0;
}
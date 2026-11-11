#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],n,m,ans;
bool cc(ll x,ll on){
	ll sum=0;
	for(int i=on;i<=x;i++){
		sum+=a[x]-a[i];
		if(sum>m){
			return false;
		}
	}
	return sum<=m;
}
void erfen(ll l,ll r,ll o){
	while(l<=r){
		ll mid=(l+r)/2;
		if(cc(mid,o)){
			ans=max(mid-o+1,ans);
			l=mid+1;
		}else{
			r=mid-1;
			if(r-o<=ans){
				return ;
			}
		}
	}
}//Oct31==Dec25?
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll nx=n;
	if(n>=100000){
		erfen(1,n,1);
		cout<<ans;
		return 0;
	}
	for(ll i=1;i<=nx;i++){
		erfen(i,n,i);
		nx=n-ans;
	}
	cout<<ans;
	return 0;
}

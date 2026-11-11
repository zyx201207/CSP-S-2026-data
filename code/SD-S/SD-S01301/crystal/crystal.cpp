#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const ll N=500010;
ll n,m;
ll q[N];
ll sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	sort(q+1,q+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+q[i];
	}
	ll ans=1;
	for(ll i=2;i<=n;i++){
		ll mid,l=1,r=i-1;
		while(l<r){
			mid=(l+r)/2;
//			cout<<ans<<" "<<(ll)((ll)((ll)(i-mid)*(q[i]))-(sum[i-1]-sum[mid-1]))<<"  "<<i<<" "<<l<<" "<<r<<" "<<mid<<" "<<((ll)(i-mid)*(q[i]))<<" "<<sum[i-1]-sum[mid-1]<<"\n";
			if(((ll)((ll)q[i]*(i-mid))-(sum[i-1]-sum[mid-1]))<=m)r=mid;
			else l=mid+1;
		}
//		cout<<i<<" "<<l<<" \n";
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}


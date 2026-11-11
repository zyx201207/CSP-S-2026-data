#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<climits>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=500005;
ll n,m;
ll a[N];
ll presum[N];
ll ans;
inline ll query(ll l,ll r) {
	return presum[r]-presum[l-1];
}
bool check(ll mid,ll u){
	//mid~u
	ll len=u-mid+1;
	ll s=query(mid,u);
	if(a[u]*len-s<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	presum[0]=0;
	for(int i=1; i<=n; i++){
		presum[i]=presum[i-1]+a[i];
	}
	for(int i=n;i>0;i--){
		ll cnt=n;
		int l=1,r=i;
		while(l<=r){
			ll mid=l+(r-l)/2;
			if(check(mid,i)){
				cnt=min(cnt,mid);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-cnt+1);
	}
	cout<<ans<<'\n';
	return 0;
}


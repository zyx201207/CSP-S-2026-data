#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N];
ll n,m,num;
inline bool check(ll mid){
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=mid) continue;
		else cnt+=mid-a[i];
		num++;
	} 
	if(cnt<=m){
		for(int i=1;i<=n;i++){
			if(a[i]==mid) num++;
		}
	}
	return cnt<=m;
}
ll maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	ll l=-maxn,r=maxn;
	ll ans=0;
	while(l<=r){
		ll mid=l+r>>1;
		num=0;
		//cout<<mid<<endl;
		if(check(mid)){
			ans=max(ans,num);
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}

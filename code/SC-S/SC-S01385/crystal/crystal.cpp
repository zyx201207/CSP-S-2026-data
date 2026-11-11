#include<bits/stdc++.h>
using ll=long long;
using namespace std;
ll n,m;
ll a[500010];
ll b[500010];
bool check_2(){
	for(int i=1;i<=n;++i){
		if(a[i]!=i) return 0;
	}
	return 1;
}
bool check(ll k,ll p){
	ll t=lower_bound(a+1,a+n+1,p)-a-1;
	ll cur=((p-a[t-k+1])+(p-a[t]))*k/2;
	if(cur>m) return 0;
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin>>n>>m;
	ll maxx=0;
	ll minn=INT_MAX;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1);
	if(check_2()){
		pair<ll,ll> p;
		for(ll i=1;i<=n;++i){
			ll idx=upper_bound(a+1,a+n+1,i)-a-1;
			ll l=1,r=idx;
			while(l<r-1){
				ll mid=(l+r)/2;
				if(check(mid,i)) l=mid;
				else r=mid-1;
			}
			if(check(r,i)){
				if(p.first<r){
					p.first=r;
					p.second=i;
				}
			}
			else{
				if(p.first<l){
					p.first=l;
					p.second=i;
				}
			}
		}
		bool flag=0;
		for(ll i=1;i<=n;++i){
			if(a[i]==p.second){
				flag=1;
				break;
			}
		}
		ll cnt=0;
		if(flag){
			ll pre=lower_bound(a+1,a+n+1,p.second)-a;
			ll nxt=upper_bound(a+1,a+n+1,p.second)-a;
			cnt=nxt-pre;
		}
		cout<<p.first+cnt;
		return 0;
	}
	ll ans=0;
	for(ll i=minn;i<=maxx;++i){
		ll cur=m;
		ll cnt=0;
		for(int j=1;j<=n;++j) b[j]=a[j];
		ll idx=lower_bound(a+1,a+n+1,i)-a-1;
		for(int j=idx;j>=1;--j){
			int diff=i-a[j];
			if(cur>=diff) cur-=diff,b[j]+=diff;
			else break;
		}
		for(int j=1;j<=n;++j) if(b[j]==i) ++cnt;
		ans=max(ans,cnt);
	}
	return cout<<ans,0;
}
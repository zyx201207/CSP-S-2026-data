#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll n,m,a[N],ans=0;
inline void dfs(ll cnt1,ll cnt2,ll now){
	if(cnt1==n+1){
		if(cnt2==m) ans=max(ans,now);
		return ;
	}
	ll now2;
	if(now==-1) now2=a[cnt1];
	else now2=now&a[cnt1];
	dfs(cnt1+1,cnt2+1,now2);
	dfs(cnt1+1,cnt2,now);
	return ; 
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0,-1);
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1){
		for(ll i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans<<'\n';
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(ll i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans<<'\n';
		return 0;
	}
	if(m==2){
		for(ll l=1;l<=n;l++){
			for(ll r=1;r<=n;r++){
				if(l!=r) ans=max(ans,a[l]&a[r]);
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	dfs(1,0,-1);
	cout<<ans<<'\n';
	return 0;
}

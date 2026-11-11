#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m,a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		int kk;
		scanf("%d",&kk);a[i]=kk;
	}
	sort(a+1,a+n+1);
	ll l=1,cost=0,cnt=0;
	for(ll r=1;r<=n;r++){
		cost+=(r-l)*(a[r]-a[r-1]);
		cnt++;
		while(cost>m){
			cost-=(a[r]-a[l]);l++;
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
/*
*/

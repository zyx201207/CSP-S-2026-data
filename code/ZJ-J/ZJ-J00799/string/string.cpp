#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mx=2e5+5;
ll n,cnt[mx],ans;
char a[mx];
int main(){
	//100pts
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>cnt[i]>>a[i];
	ll l=1,r=n;
	while(l<r){
		ll t=min(cnt[l],cnt[r]);
		cnt[l]-=t;
		cnt[r]-=t;
		if(a[l]!=a[r]) ans+=t;
		if(!cnt[l]) l++;
		if(!cnt[r]) r--;
//		cout<<l<<" "<<r<<" "<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
//开ll了，已去掉freopen的注释 
//大样例全过
//9:20结 

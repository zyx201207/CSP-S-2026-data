//郭昕宇 西安市铁一中学 SN-S00363 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],s[500005],n,m;
bool check(ll len){
	for(ll i=1;i<=n-len+1;i++){
		ll j=i+len-1;
		ll k=a[j]*len-(s[j]-s[i-1]);
		if(k<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	ll l=0,r=n;
	while(l<r){
		ll mid=(l+r)/2;
		if(mid==l){
			int ans=0;
			if(check(l))ans=l;
			if(check(r))ans=r;
			cout<<ans;
			return 0;
		}
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}

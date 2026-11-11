#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=-1,asum[5000005];
ll a[5000005];
bool cmp(ll x1,ll x2){return x1<x2;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) asum[i]=(i-1)*(a[i]-a[i-1])+asum[i-1];
	ll l=1,r=1,prl=l,prr=r;
	while(r<=n){
		ll k=asum[r]-(a[r]-a[l])*(l-1);
		if(k>m) l++;
		if(k<=m) {ans=max(ans,r-l+1);r++;}
		if(r==n) break;
		prl=l;prr=r;
		//cout<<ans<<" "<<l<<" "<<r<<endl; 
	}
	cout<<ans<<endl;
	return 0;
}

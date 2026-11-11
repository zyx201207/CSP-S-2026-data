#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005];
ll s;
ll zj(ll j,ll k,ll x){
	if(k>m)return s=max(s,x);
	for(ll i=j+1;i<=n-m+k;i++){
		if(k==1)zj(i,k+1,a[i]);
		else zj(i,k+1,x&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	zj(0,1,0);
	cout<<s;
	return 0;
}


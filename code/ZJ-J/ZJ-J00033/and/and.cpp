#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200100],n,m,f[2500][2500];
ll fi(ll x,ll k){
	if(k==0){
		return a[x];
	}
	if(x==n){
		return 0;
	}
	ll c,ma=0;
	for(ll i=x+1;i<=n;i++){
		if(f[i][k-1]==-1){
			f[i][k-1]=fi(i,k-1);
		}
		c=a[x]&f[i][k-1];
		ma=max(ma,c);
	}
	return ma;
}
ll s1[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
    }
    ll t=1;
    memset(f,-1,sizeof(f));
    for(i=1;i<=31;i++){
    	a[0]+=t;
    	t*=2;
	}
    cout<<fi(0,m);
	return 0;
}
/*
4 2
3 15 12 12
*/
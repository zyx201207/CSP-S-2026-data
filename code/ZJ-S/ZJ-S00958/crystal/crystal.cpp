#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,l=1,r;
ll a[500005],b[500005];
ll calc(ll x){
	ll c=m,res=0;
	for(int i=1;i<=n;++i){
		b[i]=a[i]-x;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i){
		if(c+b[i]>=0&&b[i]<=0){
			c+=b[i];
			++res;
		}else break;
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		r=max(a[i],r);
	}
	calc(1);
	while(l+3<r){
		ll m1=l*2/3+r/3,m2=l/3+r*2/3; //m1<m2
		if(calc(m1)>calc(m2)){
			r=m2-1;
		}else{
			l=m1+1;
		}
	}
	ll ans=0;
	for(int i=l;i<=r;++i){
		ans=max(ans,calc(i));
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
---
5 8
-3 -1 2 2 7
*/
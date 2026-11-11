#include<bits/stdc++.h>			//100 pts
#define N 500005
typedef long long ll;
using namespace std;
ll n,m,a[N],s[N];
bool Check(ll x){
	for(ll i=1;i+x-1<=n;i++){
		ll t=x*a[i+x-1]-(s[i+x-1]-s[i-1]);
		if(t<=m) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[1]<=0) for(ll i=1;i<=n;i++) a[i]+=llabs(a[1])+1;
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r) >> 1;
//		cout<<"l: "<<l<<"  mid: "<<mid<<"  r: "<<r<<"\n";
		if(Check(mid)){
			if(l==mid&&r==mid+1){
				l+=(Check(r)?1:0);
				break;
			}
			l=mid;
		}
		else r=mid-1;
	}
	cout<<l;
	return 0;
}

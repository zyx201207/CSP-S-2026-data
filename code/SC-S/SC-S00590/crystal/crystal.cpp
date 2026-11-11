#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[500005];
unsigned ll m,s=0;
ll c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		c[i]=a[i]+c[i-1];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	ll l=2,r=2,mx=1;
	while(l<=n){
		s=0;
		for(ll i=l;i<=r;i++){
			s+=a[r]-a[i-1];
//			cout<<l<<" "<<r<<" "<<i<<" "<<s<<" "<<(a[r]-a[i-1])<<"\n";
		}
		s=0-c[r-1]+(a[r]*(r-l+1))+c[l-2];
		if(s<=m){
			mx=max(mx,(r-l+2));
			if(r>=n){
				break;
			}
			r++;
		}
		else{
			l++;
			r=min(max(l,r),n);
		}
	}
	cout<<mx;
	return 0;
}
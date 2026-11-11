#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;
const ll M=1e18+5;

ll n,m,ans=0;
ll a[N];
ll s[N];

ll check(ll x){
	ll l=1,r=x,mid,d=x;
	while(l<=r){
		mid=(l+r)/2;
		if((a[x]*(x-mid+1))-(s[x]-s[mid-1])<=m){
			d=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return (x-d+1);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i]; 
	}
	for(ll i=1;i<=n;i++){
		ans=max(ans,check(i));
	}
	
	cout<<ans;
	return 0;
}
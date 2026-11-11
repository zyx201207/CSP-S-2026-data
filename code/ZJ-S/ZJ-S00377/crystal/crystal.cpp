#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005],b[500005];

int main(){
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	ll l=1,sm=0,ans=0,s=0;
	for(ll r=1;r<n;r++){
		s++;
		sm+=b[r]*s;
		while(sm>m&&l<=r){
			sm-=a[r+1]-a[l];
			l++;
			s--;
		}
		if(l>r) break;
		ans=max(ans,r-l+2);
	}
	cout<<ans;
	return 0;
}
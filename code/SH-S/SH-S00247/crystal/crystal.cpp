#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	ll ans=0;
	ll nt=0;
	sort(a+1,a+1+n);
	//for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
	//cout<<"\n";
	ll l=1,r=1;
	while(r<=n){
		while(nt<=m&&r<=n){
			ans=max(ans,r-l+1);
			r++;
			nt=nt+(a[r]-a[r-1])*(r-l);
		}
		while(nt>m&&l<=r){
			nt-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
} 

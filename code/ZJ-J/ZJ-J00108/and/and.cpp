#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],mx;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);	
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	ll ans=a[0];
	for(ll i=0;i<m;i++){
		ans&=a[i];
	}
	mx=ans;
	for(ll i=m;i<n;i++){
		ans|=a[i-m];
		ans&=a[i];
		mx=max(ans,mx);
	}
	cout<<mx;
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	vector<ll> A,pre;
	ll n,m;
	cin>>n>>m;
	A.resize(n+1);pre.resize(n+1);
	for(int i=1;i<=n;i++)cin>>A[i];
	sort(A.begin()+1,A.end());
	ll ans=0,p=0;
	A[0]=-1e18;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+A[i];
		if(A[i]==A[i-1]){
			if(p==0)p+=2;
			else p++;}
		else p=0;
		ans=max(ans,p);}
	ll t=0;
	for(ll i=1;i<=n;i++){
		ll l=i,r=n;
		while(l<r){
			ll mid=(l+r)>>1;
			ll k=(mid-i)*A[mid]-(pre[mid-1]-pre[i-1]);
			if(k<=m)l=mid+1;
			else r=mid;}
			t=max(t,l-i);}
	cout<<max(t,ans);
	return 0;}
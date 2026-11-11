#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,ans=1;
vector<ll> a,qz;
ll c(int l,int r){
	if(l==r){
		return 0;
	}
	if(l!=0){
		return qz[r]-(l*(a[r]-a[l-1])+qz[l-1]);
	}
	return qz[r];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int l=0,r=0;
	a.resize(n);
	qz.resize(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	qz[0]=0;
	for(int i=1;i<n;++i){
		qz[i]=qz[i-1]+(a[i]-a[i-1])*i;
	}
	while(l<=r and r<n){
		if(c(l,r)<=m){
			ans=max(ans,(ll)(r-l+1));
			++r;
		}
		else{
			++l;
		}
	}
	cout<<ans;
	return 0;
}
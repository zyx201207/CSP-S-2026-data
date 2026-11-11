#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N],b[N],n,m; 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	ll l=1,ans=0;
	for(int r=1;r<=n;r++){
		ll now=b[r]-b[l-1];
		while(b[r]-b[l-1]+m<a[r]*(r-l+1)) l++;
		ans=max(ans,r-l+1);
	} 
	cout<<ans;
	return 0;
} 

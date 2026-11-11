#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll n,m,a[N],b[N];
bool check(ll x){
	ll ans=0;
	for(int i=1;i<=n;i++)if(a[i]<=x)ans+=(x-a[i]);
	if(ans<=m)return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=a[1],r=a[n];
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)==1)l=mid+1;
		else r=mid-1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]<l)ans++;
	}
	cout<<ans;
	return 0;
}

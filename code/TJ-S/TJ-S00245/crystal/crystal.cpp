#include <bits/stdc++.h>
typedef long long ll;
using namespace std; 
ll a[500005],s[500005],n,m;
bool check(ll mid){
	for(int i=1;i+mid-1<=n;i++){
		if(a[i+mid-1]*mid-(s[i+mid-1]-s[i-1])<=m) return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<r;
}

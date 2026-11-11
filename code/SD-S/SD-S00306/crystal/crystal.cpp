#include<bits/stdc++.h>
#define ll long long
using namespace std; 
ll n,m;
int a[500005];
bool check(int x){
	for(int i=x;i<=n;i++){
		ll cnt=0;
		for(int j=i-x+1;j<=i;j++) cnt+=a[i]-a[j];
		if(cnt<=m) return 1;
	}
	return 0;
}
bool chk(int x){
	ll cnt=0;
	for(int i=1;i<=x;i++) cnt+=a[x]-a[i];
	if(cnt<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000){
		sort(a+1,a+n+1);
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)) l=mid+1;
			else r=mid-1;
		}
		cout<<l-1;
		return 0;
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
}
//雄山峻壑终踏过，需信寒过总是春 

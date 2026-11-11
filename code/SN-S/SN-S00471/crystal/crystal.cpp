//SN-S00471 田牧可 西安交通大学附属中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],dif[N],s[N],ss[N];
bool check(int len){
	for(int r=len;r<=n;r++){
		int l=r-len+1;
		ll ans=1ll*(len-1)*s[r]-(ss[r-1]-ss[l-1]);
		if(ans<=m) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) dif[i]=a[i]-a[i-1];
	s[1]=0;
	for(int i=2;i<=n;i++) s[i]=s[i-1]+dif[i];
	for(int i=1;i<=n;i++) ss[i]=ss[i-1]+s[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}

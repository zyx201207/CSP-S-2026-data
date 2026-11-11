#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int W=5e5+5;
ll n,m,a[W],b[W],l,r,mid,ans;
bool check(ll x){
	ll num=0;
	for(int i=1;i<=x;i++){
		num+=a[x]-a[i];
	}
	return num<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	ll num=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=a[r]){
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

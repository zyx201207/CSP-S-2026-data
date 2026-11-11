#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
typedef long long ll;
int n;
ll m;
ll a[MAXN];
ll sum[MAXN];
bool check(int x){
	ll res=1e18;
	for(int i=1;i<=n-x+1;i++){
		ll s=(x-1)*a[i+x-1]-sum[i+x-2]+sum[i-1];
		res=min(s,res);
	}
	return (res<=m);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
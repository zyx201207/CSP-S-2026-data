#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,m,a[N],sum[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		int need=x*a[i]-sum[i]+sum[i-x];
		if(need<=m)
			return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int h=n+1,l=0;
	while(h>l+1){
		int mid=(h+l)/2;
		if(check(mid))
			l=mid;
		else
			h=mid;
	}
	cout<<l;
	return 0;
}

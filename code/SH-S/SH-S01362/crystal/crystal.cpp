#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],sum[500010],maxx;
bool check(int x){
	for(int i=n;i>=x;i--){
		if((x*a[i]-(sum[i]-sum[i-x]))<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,mid=0;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
			maxx=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<maxx;
	return 0;
}


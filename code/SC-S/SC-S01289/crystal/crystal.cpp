#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005];
bool check(int mid){
	int ans=1e18;
	for(int i=1;i+mid-1<=n;i++){
		int tmp=mid*a[i+mid-1]-(sum[i+mid-1]-sum[i-1]);
		if(tmp<ans)ans=tmp;
	}if(ans>m)return 0;
	return 1;
}
int f(int l,int r){
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}return l-1;
}
signed main(){
	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];sum[i]=sum[i-1]+a[i];}
	sort(a+1,a+n+1);
	cout<<f(1,n);
	return 0;
}
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,ans=-0x3f3f3f3f;
long long m,sum[5000005],a[500005];
int bs(int l,int r,int i){
	int res=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(mid*a[i+mid-1]-(sum[i+mid-1]-sum[i-1])>m){
			r=mid-1;
		}else if(mid*a[i+mid-1]-(sum[i+mid-1]-sum[i-1])<=m){
			res=mid;
			l=mid+1;
		}
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,bs(1,n+1-i,i));
	}
	cout<<ans;
	return 0;
}
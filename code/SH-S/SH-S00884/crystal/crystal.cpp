#include<bits/stdc++.h>
using namespace std;
const int N=500009;
long long n,m,ans=0;
long long a[N]={},b[N]={},d[N]={};
__int128 c[N]={};
int o=0;
__int128 xdd(long long k){
	__int128 u=b[k];
	__int128 v=b[k]*(o+1);
	return c[k]-b[k]*(o+1)+d[o];
}
long long ilysyq(){//找第一个大于m的数 
	long long l=o,r=n-1;
	long long mid;
	while(1){
		mid=(l+r)/2;
		if(xdd(mid)<=m) l=mid;
		else r=mid;
		if(xdd(l)<=m&&xdd(r)>m&&r-l==1){
			return l;
		}
		if(xdd(r)<m) return -1;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		b[i]=a[i]-a[0];
		c[i]=c[max(0,i-1)]+(a[i]-a[max(0,i-1)])*i;
		d[i]=b[i]+d[max(0,i-1)];
	}
	for(int i=0;i<n;i++){
		if(ans>n-i+1) break;
		o=i;
		long long p=ilysyq();
		long long asdf;
		if(i==0) asdf=p+1;
		else asdf=p-o;
		if(asdf>ans) ans=asdf;
	}
	cout<<ans;
	return 0;
}

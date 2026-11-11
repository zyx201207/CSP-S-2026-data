#include <bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m;
long long a[N];
long long pre[N];
long long ans;
long long rfc(long long l,long long r){
	long long ma=0;
	long long rz=a[r];
	long long ry=r;
	while(l<=r){
		long long mid=(l+r)/2;
		long long x=ry-mid+1; 
		if(rz*x-(pre[ry]-pre[mid-1])>m){
			l=mid+1;
		}else if(rz*x-(pre[ry]-pre[mid-1])<=m) {
			r=mid-1;
			ma=max(ma,x);
		}
	}
	return ma;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=a[i]+pre[i-1];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,rfc(1,i));
	}
	cout<<ans;
	return 0;
}


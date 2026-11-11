#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],c[N];
bool pd(long long x){
	long long ans=0;
	for(long long i=1;i<=n-x+1;i++){
		long long s=(a[i+x-1]*(x-1))-c[i+x-2]+c[i-1];
		if(ans==0) ans=s;
		else ans=min(s,ans);
	}
	if(ans>m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++) c[i]=a[i]+c[i-1];
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(pd(mid)){
			 r=mid-1;
		 }
		else{
			 l=mid+1;
		}
	}
	cout<<l-1;
	return 0;
}

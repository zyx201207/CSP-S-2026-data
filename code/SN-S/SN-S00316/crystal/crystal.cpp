#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],s[N],k;
long long ff(long long x){
	long long l=x,r=n,mid,k=x;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]*(mid-x)-(s[mid-1]-s[x-1])<=m){
			k=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return k-x+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		k=max(k,ff(i));
	}
	cout<<k;
	return 0;
}

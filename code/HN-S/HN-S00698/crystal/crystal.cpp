#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],m,r,l,q[1000000];
bool check(long long x){
	for(long long i=1;i<=n-x+1;i++){
		//cout<<i<<' '<<x<<' '<<q[i+x-1]-q[(2*i+x)/2-1]-q[(2*i+x-1)/2]+q[i-1]<<'\n';
		if(a[i+x-1]*x-(q[i+x-1]-q[i-1])<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	l=-1,r=n+1;
	while(l+1<r){
		long long mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}
//13534423
//12333445
//1129999

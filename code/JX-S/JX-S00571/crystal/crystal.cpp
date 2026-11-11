#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],qzh[N],ans;
int pd(long long x){
	for(long long i=x;i<=n;i++){
		long long as=a[i]*x-qzh[i]+qzh[i-x];
		if(as<=m) return 1;
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
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	long long l=1,r=N;
	while(l<r){
		long long mid=(l+r+1)/2;
		ans=l;
		if(pd(mid)==1){
			l=mid;
		}
		else r=mid-1;
	}
	cout<<l;
	return 0;
}

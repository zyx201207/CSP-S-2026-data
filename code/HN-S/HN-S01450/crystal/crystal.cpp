#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
long long n,m,a[maxn]={},sum[maxn]={};
long long p(long x,long long y){
	return a[x]*(x-y+1)-(sum[x]-sum[y-1]);
}
bool check(long long x){
	long long minn=(a[n]-a[1])*n*2;
	for(long long i=1;i<=n-x+1;i++){
		minn=min(minn,p(i+x-1,i));
	}
	return minn<=m;
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
		sum[i]=sum[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r)/2+1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l<<'\n';
	return 0;
}
/**/

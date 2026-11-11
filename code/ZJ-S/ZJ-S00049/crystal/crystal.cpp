#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long arr[N];
long long sum[N];
bool check(long long x,long long n,long long m){
	for(int i=1;i<=n-x+1;i++){
		long long you=sum[i+x-1]-sum[i-1];
		long long yao=x*arr[i+x-1];
		if(yao-you<=m) return true;
	}
	return false;
}
void erfen(long long n,long long m){
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid,n,m)){
			l=mid+1;
		}else r=mid-1;
	}
	cout<<l-1;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i];
	}
	erfen(n,m);
	return 0;
}

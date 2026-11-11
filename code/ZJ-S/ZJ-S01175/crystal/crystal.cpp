#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],x[500005],l,r;
bool check(int M){
	for(long long i=2;i<=M;i++){
		x[i]=x[i-1]+(a[i]-a[i-1])*(i-1);
	}
	if(x[M]<=m){
		return 1;
	}
	for(long long i=M+1;i<=n;i++){
		x[M]=x[M]-(a[i-1]-a[i-M])+M*(a[i]-a[i-1]);
		if(x[M]<=m){
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
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<r){
		long long mid=(l+r)/2+1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

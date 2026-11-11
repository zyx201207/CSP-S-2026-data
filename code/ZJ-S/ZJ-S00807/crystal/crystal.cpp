#include<iostream>
#include<algorithm>
using namespace std;
long long a[500010];
long long q[500010];
long long n,m;
long long ans;
int check(int l,int r){
	long long t=a[r]*(r-l+1)-(q[r]-q[l-1]);
	if(t<=m){
		return 1;
	}
	else{
		return 0;
	}
}
long long cry(int x){
	int l=1,r=x;
	long long ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid,x)){
			ans=x-mid+1;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long ansp=cry(i);
		if(ansp>ans){
			ans=ansp;
		}
	}
	printf("%lld",ans);
	return 0;
}
//luogu uid:995895
//RP++
//I heard that if I write a Xiong Da and a Xiong Er,
//Guang Touqiang can't reach my main function. :)

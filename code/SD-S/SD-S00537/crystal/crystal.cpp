#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
long long a[N],m,sum[N];
int ans=1,n;
int twofen(int x){
	int l=1,r=x,num=x;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[x]*(x-mid)-(sum[x-1]-sum[mid-1])<=m){
			num=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return x-num+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1,x;i<=n;i++){
		x=twofen(i);
		ans=max(x,ans);
	}
	printf("%d",ans);
	return 0;
}


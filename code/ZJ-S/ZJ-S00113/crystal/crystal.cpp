#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n;
long long m;
long long a[N],sum[N];
bool check(int x){//x:len of qujian
	int tl;
	for(int hd=x,tl=1;hd<=n;hd++,tl=hd-x+1){//head tail
		//cout<<"["<<hd<<" "<<tl<<" "<<a[hd]*x-(sum[hd]-sum[tl-1])<<"]"<<endl;;
		if(a[hd]*x-(sum[hd]-sum[tl-1])<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		//cout<<"{"<<l<<","<<mid<<","<<r<<"}\n";
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	printf("%d",l);
	return 0;
}

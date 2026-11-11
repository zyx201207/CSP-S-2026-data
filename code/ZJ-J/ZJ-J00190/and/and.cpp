#include<bits/stdc++.h>
using namespace std;
long long n,m,anss,a[200005],rest,xx;
bool cmp(long long x,long long y){
	return ((x&(1LL<<xx))>(y&(1LL<<xx)));
}
void check(){
	sort(a+1,a+1+n,cmp);
	long long l=1,r=n+1,ans=0;
	while(l<r){
		long long mid=(l+r)>>1;
		if((a[mid]&(1LL<<xx))!=0){
			l=mid+1;
			ans=mid;
		}else{
			r=mid;
		}
	}
	if(n-ans<=rest){
		anss=anss+(1LL<<xx);
		rest-=(n-ans);
		n=ans;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	rest=n-m;
	for(long long i=1;i<=n;++i){
		cin>>a[i];
	}
	for(long long i=29;i>=0;--i){
		xx=i;
		check();
	}
	cout<<anss;
	return 0;
}
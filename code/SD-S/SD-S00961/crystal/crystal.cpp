#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long ret=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-') f*=-1;c=getchar();}
	while(c>='0' && c<='9'){ret=ret*10+c-48;c=getchar();}
	return ret*f;
}
long long a[500005];
long long sum[500005];
long long n,m;
bool check(int x){
	long long summ=9223372036854775807;
	for(int i=x;i<=n;i++){
		summ=min(summ,x*a[i]-sum[i]+sum[i-x]);
		if(summ<=m) return 1;
	}
	if(summ<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) sum[i]=a[i]+sum[i-1];
	int l=0,r=n+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int max_n=5e5+5;
long long n,m,a[max_n],sum[max_n];
long long ans=1;
long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l=1,r=1;
	while(l<=n&&r<=n){
		r++; 
		while(r<=n){
			long long cntm=(r-l+1)*a[r]-(sum[r]-sum[l-1]);
			if(cntm<=m){
				ans=max(ans,r-l+1);
				r++;
			}
			else{
				break;
			}
		}
		while(l<=r){
			long long cntm_=(r-l+1)*a[r]-(sum[r]-sum[l-1]);
			if(cntm_>m){
				l++;
			}
			else{
				break;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}


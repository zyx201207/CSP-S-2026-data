#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long c=1,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			c=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';ch=getchar();
	}
	return c*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');write(-1*x);return;
	}
	if(x>=10){
		write(x/10);
	}
	putchar('0'+x%10);
	return;
}
const long long N=500105;
long long n,m,a[N],sum[N],ans; 
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long l=1,r=i,res=i;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				r=mid-1;res=mid;
			}
			else{
				l=mid+1; 
			} 
		}
		ans=max(ans,i-res+1);
	}
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

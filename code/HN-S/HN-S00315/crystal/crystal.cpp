#include<bits/stdc++.h>
using namespace std;
long long n,m,s,a[500010],b[500010];
long long read(){
	long long f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
void write(long long v){
	if(v<0) putchar('-'),v=-v;
	if(v<10) putchar(v+'0');
	else{
		write(v/10);
		putchar(v%10+'0');
	}
}
void check(int x){
	int l1=-1,r1=x,mx=0;
	while(l1+1<r1){
		int mid=(l1+r1)/2;
		if(a[x]*(x-1-mid+1)-(b[x-1]-b[mid-1])>m){
			l1=mid;
		}else{
			r1=mid,mx=max(x-1-mid+1,mx);
		}
	}
	if(mx+1>=s) s=mx+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=n;i>=1;i--) check(i);
	write(s);
	return 0;
}

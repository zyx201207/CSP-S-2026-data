//CSP-S 2026 A
//Last change time:18:23:33
//E(Points): 100pts
#include<bits/stdc++.h>
#define ps putchar(32)
#define el putchar(10)
using namespace std;
long long read(){
	long long f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return (f==1)?x:-x;
}
void write(long long x){
	if(x<0){putchar(45);x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const long long N=5e5+5;
long long n,m,a[N],s[N];
bool check(long long x){
	for(long long i=x;i<=n;i++){
		long long sum=a[i]*x-(s[i]-s[i-x]);
		if(sum<=m)return true;
	}return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(long long i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	long long L=1,R=n,ans=0;
	while(L<=R){
		long long mid=(L+R)>>1;
		if(check(mid))L=mid+1,ans=mid;
		else R=mid-1;
	}write(ans);el;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long read(){
	long long f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return;
}
long long n,m,a[N],ans,ll=1,su;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		while(a[i]*(i-ll+1)-su-a[i]>m){
			su-=a[ll];
			ll++;
		}
		su+=a[i];
		ans=max(ans,i-ll+1);
	}
	write(ans);
	return 0;
}

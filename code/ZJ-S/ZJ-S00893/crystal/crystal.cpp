#include<bits/stdc++.h>
#define int long long
#define debug printf("!!!\n")
using namespace std;
int read(){
	char c=getchar();
	int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void write(int x,char c){
	write(x);putchar(c);
}
const int N=5e5+5;
int n,m,a[N],ans,s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int l=1,r=1;l<=n;l++){
		for(;r<=n&&a[r]*(r-l+1)-(s[r]-s[l-1])<=m;r++);
		r--;ans=max(ans,r-l+1);
	}
	write(ans,'\n');
	return 0;
}
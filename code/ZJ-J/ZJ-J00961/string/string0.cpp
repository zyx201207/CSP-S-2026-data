#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
	int ret=0;char ch=getchar();bool sgn=0;
	while(!isdigit(ch)) sgn^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn?-ret:ret;
}
int n,ans;
struct mine{
	int num;
	char ch;
}a[200005];
char s[2000005];
char gc(){char ch=getchar();while(ch>'z'||ch<'a') ch=getchar();return ch;}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string0.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i].num=read(),a[i].ch=gc();
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].num;j++) s[++cnt]=a[i].ch;
	}
	for(int i=1;i<cnt+1-i;i++){
		if(s[i]!=s[cnt+1-i]) ans++;
	}
	printf("%lld",ans);
	return 0;
}

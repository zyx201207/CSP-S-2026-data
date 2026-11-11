#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int ret=0;char ch=getchar();bool sgn=0;
	while(!isdigit(ch)) sgn^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn?-ret:ret;
}
char gc(){char ch=getchar();while(ch>'z'||ch<'a') ch=getchar();return ch;}
int n,ans;
struct mine{
	int num;
	char ch;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i].num=read(),a[i].ch=gc();
	for(int i=1,j=n,ilen=0,jlen=0;i<j;){
		if(a[i].num-ilen<a[j].num-jlen){
			jlen+=a[i].num-ilen;
			if(a[i].ch!=a[j].ch) ans+=a[i].num-ilen;
			i++,ilen=0;
		}else if(a[i].num-ilen>a[j].num-jlen){
			ilen+=a[j].num-jlen;
			if(a[i].ch!=a[j].ch) ans+=a[j].num-jlen;
			j--,jlen=0;
		}else{
			if(a[i].ch!=a[j].ch) ans+=a[j].num-jlen;
			i++,j--,jlen=ilen=0;
		}
	}
	printf("%lld",ans);
	return 0;
}

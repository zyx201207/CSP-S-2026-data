#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n;
int a[N];
char c[N];
long long ans;
int read(){
	int k=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		k=(k<<1)+(k<<3)+(ch^48);
		ch=getchar();
	}
	return k;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i]=read();
		c[i]=getchar();
	}
	int lq=1,rq=n,lw=a[1],rw=a[n];
	while(lq<rq){
		int mo=min(lw,rw);
		if(c[lq]!=c[rq])ans+=mo;
		if(mo==lw){
			lq++;lw=a[lq];
		}
		else lw-=mo;
		if(mo==rw){
			rq--;rw=a[rq];
		}
		else rw-=mo;
	}
	printf("%lld",ans);
	return 0;
}

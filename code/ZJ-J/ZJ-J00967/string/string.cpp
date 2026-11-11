#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=2*1e5+5;
int n,a[maxn];
char c[maxn];
LL ans;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		c[i]=getchar();
		if(c[i]>'z'||c[i]<'a') c[i]=getchar();
	}
	if(n==1){printf("0");return 0;}
	int i=1,j=n;
	while(i<j){
		if(c[i]!=c[j]) ans+=min(a[i],a[j]);
		if(a[i]==a[j]) i++,j--;
		else if(a[i]>a[j]) a[i]-=a[j],a[j]=0,j--;
		else a[j]-=a[i],a[i]=0,i++;
	}
	printf("%lld",ans);
	return 0;
}
// I love CCF!!!
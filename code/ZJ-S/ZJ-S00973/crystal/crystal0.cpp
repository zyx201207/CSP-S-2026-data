#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int ret=0;char ch=getchar();bool sgn=0;
	while(!isdigit(ch)) sgn^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn?-ret:ret;
}
int n,m,L,R,ans=1,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal0.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int hs=m,sum=1;
		for(int j=i-1;j&&hs>=a[i]-a[j];j--) hs-=a[i]-a[j],sum++;
		ans=max(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
#include <bits/stdc++.h>
#define int long long
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define F(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
const int N=5e5+1;
int n,m,a[N],ans,cnt=1,hd=1,tl=1;
inline int read(){
	int X=0,F=1;char C=getchar();
	while(C<'0'||C>'9'){if(C=='-') F=-1;C=getchar();}
	while(C>='0'&&C<='9'){X=X*10+C-'0';C=getchar();}
	return X*F;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	f(i,1,n,1) a[i]=read();
	sort(a+1,a+n+1);
	while(tl<=n){
		while(tl<n&&cnt*(a[tl+1]-a[tl])<=m)
		{m-=(a[tl+1]-a[tl])*cnt;tl++;cnt++;}
		ans=max(ans,cnt);
		if(tl==n) break;
		if(cnt!=1){m+=a[tl]-a[hd];hd++;cnt--;}
		else{hd++;tl++;}
	}
	printf("%lld",ans);
	return 0;
}

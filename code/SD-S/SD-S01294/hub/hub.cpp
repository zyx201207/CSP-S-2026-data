#include <bits/stdc++.h>
//#define int long long
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define F(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
const int N=2e5+1;
int c,T,n,k,u,v;
inline int read(){
	int X=0,F=1;char C=getchar();
	while(C<'0'||C>'9'){if(C=='-') F=-1;C=getchar();}
	while(C>='0'&&C<='9'){X=X*10+C-'0';C=getchar();}
	return X*F;
} 
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	if(c==13||c==14) while(T--){
		n=read(),k=read();
		f(i,2,n,1) u=read(),v=read();
		int m=n>>1,ans=1;
		while(k<m){ans++;m>>=1;}
		printf("%d\n",m);
	}
	return 0;
}

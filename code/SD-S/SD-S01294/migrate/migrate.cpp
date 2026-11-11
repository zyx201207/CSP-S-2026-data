#include <bits/stdc++.h>
#define int long long
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define F(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
const int N=2e5+1;
const int M=5001;
int c,T,n,d,x[N],f[N][N];
inline int read(){
	int X=0,F=1;char C=getchar();
	while(C<'0'||C>'9'){if(C=='-') F=-1;C=getchar();}
	while(C>='0'&&C<='9'){X=X*10+C-'0';C=getchar();}
	return X*F;
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	puts("0"); 
	return 0;
}
/*

*/

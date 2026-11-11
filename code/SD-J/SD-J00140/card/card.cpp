#include<bits/stdc++.h>
#define up(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define dn(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define INF 200005
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
	return x*f;
}
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	up(i,1,n,1) int x=read();
	srand(time(0));
	up(i,1,m,1) cout<<(rand()%m)<<" ";
	return 0;
}

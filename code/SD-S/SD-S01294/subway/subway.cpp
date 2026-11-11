#include <bits/stdc++.h>
#define int long long
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define F(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
const int N=5e5+1;
const int M=501;
const int INF=0x7ffffffffffffff;
int c,n,m,d,q,w[N],k,x,y,h[M][M];
struct sttn{int s,t;};//station
vector <sttn> ve[N];
int ans,cnt;
inline int read(){
	int X=0,F=1;char C=getchar();
	while(C<'0'||C>'9'){if(C=='-') F=-1;C=getchar();}
	while(C>='0'&&C<='9'){X=X*10+C-'0';C=getchar();}
	return X*F;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	f(i,1,n,1) f(j,1,n,1) if(i!=j) h[i][j]=INF;
	f(i,1,m,1) w[i]=read();
	f(i,1,n,1){
		k=read();
		while(k--){
			int A=read(),T=read();
			for(auto v:ve[A])
				h[v.s][i]=h[i][v.s]=min(h[i][v.s],v.t+T);
			ve[A].push_back({i,T});
		}
	}
	f(l,1,n,1) f(i,1,n,1) f(j,i+1,n,1) if(i!=j)
		h[i][j]=min(h[i][j],h[i][l]+h[l][j]);
	f(i,1,n,1) f(j,i+1,n,1) h[j][i]=h[i][j]=min(h[i][j],h[j][i]);
	
	while(q--){
		ans=INF;
		x=read(),y=read();
		for(auto v1:ve[x]) for(auto v2:ve[y]){
			cnt=v1.t+v2.t;cnt+=h[v1.s][v2.s];
			ans=min(ans,cnt);
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}

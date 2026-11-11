#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
inline int read(){
	int n=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')n=n*10+c-'0',c=getchar();
	return n*f;
}
inline void chkmax(int &a,int b){a=max(a,b);}
inline void chkmin(int &a,int b){a=min(a,b);}
const int N=505,M=5e5+5,D=21;
const int inf=2e18;
int n,m,d,q;
int w[M];
struct station{
	int x,w;
};
station st[M][D];
int ec[M];
int e[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C=read();
	n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=1;i<=n;++i){
		int k=read();
		for(int j=1;j<=k;++j){
			int a=read(),t=read();
			++ex[a];
			st[a][ec[a]]={i,t};
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)e[i][j]=i==j?0:inf;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=ec[i];++j){
			for(int k=j+1;k<=ec[i];++k){
				int x=st[i][j].x,y=st[i][k].x,val=st[i][j].w+st[i][k].w;
				chkmin(e[x][y],val);
				chkmin(e[y][x],val);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				chkmin(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		int ans=inf;
		for(int i=1;i<=ec[i];++i){
			for(int j=1;j<=ec[i];++j){
				chkmin(ans,e[st[x][i].x][st[y][j].x]+st[x][i].w+st[y][j].w+w[x]+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}


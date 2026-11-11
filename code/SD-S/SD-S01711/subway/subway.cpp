#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 _int;
typedef unsigned char uc;
typedef unsigned int ui;
char buf[1000010],obuf[1000010],*p1,*p2,*p3=obuf;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
#define pc(x) (p3==obuf+1000000&&fwrite(p3=obuf,1,1000000,stdout),*p3++=x)
int read(){
	int x=0;
	bool f=1;
	char c=gc();
	while(c<48||c>57){
		if(c=='-'){
			f=0;
		}
		c=gc();
	}
	while(c>47&&c<58){
		x=(x<<3)+(x<<1)+(c&15);
		c=gc();
	}
	return f?x:-x;
}
ll lread(){
	ll x=0;
	bool f=1;
	char c=gc();
	while(c<48||c>57){
		if(c=='-'){
			f=0;
		}
		c=gc();
	}
	while(c>47&&c<58){
		x=(x<<3)+(x<<1)+(c&15);
		c=gc();
	}
	return f?x:-x;
}
template<typename Tp>
void write(Tp x){
	if(x<0){
		pc('-');
		x=-x;
	}
	static char stk[40];
	int top=0;
	do{
		stk[top++]=x%10|48;
	}while(x/=10);
	while(top--){
		pc(stk[top]);
	}
}
template<typename Tp,typename Tp2>
void chmin(Tp&x,const Tp2&y){
	if(y<x){
		x=y;
	}
}
template<typename Tp,typename Tp2>
void chmax(Tp&x,const Tp2&y){
	if(x<y){
		x=y;
	}
}
namespace AIMAT{
	const int N=510,M=5.01e5;
	ll f[N][N];
	int a[M],id[M][25],w[M][25],cnt[M];
	void main(){
		read();
		int n=read(),m=read(),Q,k,u,v;
		read();
		Q=read();
		for(int i=1;i<=m;++i){
			a[i]=read();
		}
		for(int i=1;i<=n;++i){
			k=read();
			while(k--){
				++cnt[u=read()];
				id[u][cnt[u]]=i;
				w[u][cnt[u]]=read();
			}
		}
		memset(f,0x3f,sizeof f);
		for(int i=1;i<=n;++i){
			f[i][i]=0;
		}
		for(int i=1;i<=m;++i){
			for(int j=1;j<=cnt[i];++j){
				for(int k=1;k<j;++k){
					chmin(f[id[i][j]][id[i][k]],w[i][j]+w[i][k]);
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<i;++j){
				chmin(f[i][j],f[j][i]);
				chmin(f[j][i],f[i][j]);
			}
		}
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					chmin(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		while(Q--){
			u=read();
			v=read();
			ll ans=1e18;
			for(int i=1;i<=cnt[u];++i){
				for(int j=1;j<=cnt[v];++j){
					chmin(ans,w[u][i]+w[v][j]+f[id[u][i]][id[v][j]]);
				}
			}
			write(ans+a[u]+a[v]);
			pc('\n');
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int testcase=1;
	while(testcase--){
		AIMAT::main();
	}
	fwrite(obuf,1,p3-obuf,stdout);
	return 0;
}

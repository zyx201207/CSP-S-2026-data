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
	const int N=1.01e6;
	struct EDGE{
		int nxt,to;
	}edge[N*2];
	int n,K,D,head[N],tot,md[N],f[N],f1[N],f2[N],f3[N],g1[N],g2[N],g3[N],fa[N];
	void add(int u,int v){
		edge[++tot].nxt=head[u];
		edge[head[u]=tot].to=v;
	}
	void dfs(int now){
		md[now]=0;
		for(int i=head[now],v;i;i=edge[i].nxt){
			if((v=edge[i].to)!=fa[now]){
				fa[v]=now;
				dfs(v);
				chmax(md[now],md[v]+1);
			}
		}
	}
	void dfs1(int now){
		int cnt=0,sumd=0;
		f[now]=md[now]>=D;
		f1[now]=f2[now]=0;
		f3[now]=1e9;
		for(int i=head[now],v;i;i=edge[i].nxt){
			if((v=edge[i].to)!=fa[now]){
				dfs1(v);
				f[now]+=f[v];
				chmax(f2[now],f2[v]+1);
				chmin(f3[now],f3[v]+1);
				if(f1[v]){
					f1[now]+=f1[v];
					++cnt;
					sumd+=f3[v];
				}
			}
		}
		if(cnt>1||f2[now]==D){
			f1[now]+=sumd+1;
			f3[now]=0;
		}
		if(f2[now]+f3[now]<=D){
			f2[now]=-1e9;
		}
	}
	void dfs2(int now){
		int cnt=!!g1[now],sum=g1[now],mx=g2[now]+1,mxx=-1e9,mn=g3[now]+1,mnn=1e9,sumd=g1[now]?g3[now]:0;
		for(int i=head[now],v;i;i=edge[i].nxt){
			if((v=edge[i].to)!=fa[now]){
				if(f1[v]){
					sum+=f1[v];
					++cnt;
					sumd+=f3[v];
				}
				if(f2[v]>=mx){
					mxx=mx;
					mx=f2[v]+1;
				}else{
					chmax(mxx,f2[v]+1);
				}
				if(f3[v]<mn){
					mnn=mn;
					mn=f3[v]+1;
				}else{
					chmin(mnn,f3[v]+1);
				}
			}
		}
		for(int i=head[now],v;i;i=edge[i].nxt){
			if((v=edge[i].to)!=fa[now]){
				g1[v]=sum-f1[v];
				g2[v]=max(0,mx==f2[v]+1?mxx:mx);
				g3[v]=mn==f3[v]+1?mnn:mn;
				if(cnt-!!f1[v]>1||g2[v]==D){
					g1[v]+=sumd-(f1[v]?f3[v]:0)+1;
					g3[v]=0;
				}
				if(g2[v]+g3[v]<=D){
					g2[v]=-1e9;
				}
				dfs2(v);
			}
		}
	}
	bool check(){
		dfs1(1);
		dfs2(1);
		for(int i=1;i<=n;++i){
			if(max(f[i],1)+g1[i]<=K){
				return 1;
			}
		}
		return 0;
	}
	void main(){
		n=read();
		int u,v;
		tot=0;
		memset(head+1,0,n<<2);
		K=read();
		for(int i=1;i<n;++i){
			add(u=read(),v=read());
			add(v,u);
		}
		dfs(1);
		g2[1]=-1e9;
		g3[1]=1e9;
		int l=0,r=n-1;
		while(l<=r){
			int mid=D=l+r>>1;
			if(check()){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		write(l);
		pc('\n');
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read();
	int testcase=read();
	while(testcase--){
		AIMAT::main();
	}
	fwrite(obuf,1,p3-obuf,stdout);
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace IO{
	inline ll read(){
		ll res=0;
		bool flg=true;
		char c=getchar();
		while(c<'0'||'9'<c){
			if(c=='-') flg=false;
			c=getchar();
		}
		while('0'<=c&&c<='9'){
			res=(res<<3)+(res<<1)+(c&15);
			c=getchar();
		}return flg?res:-res;
	}
	inline void print(ll num){
		if(num>9) print(num/10);
		putchar('0'+num%10);
		return;
	}
	inline void write(ll num){
		if(num<0) putchar('-'),num=-num;
		print(num);
		putchar('\n');
		return;
	}
}
using namespace IO;
const int kMaxN=1e6+5,inf=1e9+7;
int n,m,T,id;
namespace Tree{
	struct E{
		int to,qx;
	}e[kMaxN<<1];
	int hd[kMaxN],elen=0;
	inline void addeg(int x,int y){
		++elen;
		e[elen]=(E){y,hd[x]};
		hd[x]=elen;
		return;
	}
	int fa[2][kMaxN];
	int dst[2][kMaxN];
	inline void dfs1(int tp,int u,int p,int uu){
		fa[tp][u]=p;
		dst[tp][u]=dst[tp][p]+1;
//		dst[tp][u]=min(dst[tp][u],dst[tp][p]+1);
		int i,v;
		for(i=hd[u];i;i=e[i].qx){
			v=e[i].to;
			if(v==p||v==uu) continue;
			dfs1(tp,v,u,uu);
		}
		for(i=hd[u];i;i=e[i].qx){
			v=e[i].to;
			if(v==p||v==uu) continue;
			dst[tp][u]=max(dst[tp][u],dst[tp][v]);
		}return;
	}
}
using namespace Tree;
struct D{
	int xb,w,tp;
	inline bool friend operator<(D x,D y){
		return x.w<y.w;
	}
};
priority_queue<D> pq;
int ans=inf;
inline void solve1(int x){
	int i,u,v,czs=m;
	for(i=1;i<=n;++i) dst[0][i]=inf;
	dst[0][x]=1;
	dfs1(0,x,0,0);
//	for(i=1;i<=n;++i) cerr<<dst[0][i]<<' ';
//	cerr<<'\n';
	while(!pq.empty()) pq.pop();
	pq.push((D){x,dst[0][x],0});
	while(!pq.empty()&&czs>0){
		u=pq.top().xb;
		pq.pop();
		czs-=1;
		for(i=hd[u];i;i=e[i].qx){
			v=e[i].to;
			if(v==fa[0][u]) continue;
			dst[0][v]-=1;
			pq.push((D){v,dst[0][v],0});
		}
	}
	czs=0;
	while(!pq.empty()){
		v=pq.top().xb;
		czs=max(czs,dst[0][v]);
		pq.pop();
	}
	ans=min(ans,czs);
//	cerr<<x<<' '<<0<<' '<<czs<<'\n';
	return;
}
inline void solve2(int x,int y){
	int i,u,v,czs=m,tp;
	for(i=1;i<=n;++i) dst[0][i]=inf,dst[1][i]=inf;
	dst[0][x]=1; dfs1(0,x,0,y);
	dst[1][y]=1; dfs1(1,y,0,x);
//	for(i=1;i<=n;++i) cerr<<dst[0][i]<<' ';
//	cerr<<'\n';
//	for(i=1;i<=n;++i) cerr<<dst[1][i]<<' ';
//	cerr<<"\n\n";
	while(!pq.empty()) pq.pop();
	pq.push((D){x,dst[0][x],0});
	pq.push((D){y,dst[1][y],1});
	while(!pq.empty()&&czs>0){
		u=pq.top().xb;
		tp=pq.top().tp;
		pq.pop();
		czs-=1;
		for(i=hd[u];i;i=e[i].qx){
			v=e[i].to;
			if(v==fa[tp][u]) continue;
			dst[tp][v]-=1;
			pq.push((D){v,min(dst[0][v],dst[1][v]),tp});
		}
	}
	czs=0;
	while(!pq.empty()){
		v=pq.top().xb;
		czs=max(czs,min(dst[0][v],dst[1][v]));
//		cerr<<v<<' '<<min(dst[0][v],dst[1][v])<<'\n';
		pq.pop();
	}
//	cerr<<x<<' '<<y<<' '<<czs<<'\n';
	ans=min(ans,czs);
	return;
}
inline void Solve(){
	ans=inf;
	int i,j;
	for(i=1;i<=n;++i){
		for(j=1;j<=i;++j){
			if(i==j){
				solve1(i);
			}
			else{
				solve2(i,j);
			}
		}
	}
	write(ans);
	return;
}
inline void init(){
	int i;
	elen=0;
	for(i=1;i<=n;++i) hd[i]=0;
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	freopen("hub3.in","r",stdin);
//	freopen("hub.out","w",stdout);
	int i,x,y;
	id=read(),T=read();
	for(;T;--T){
		n=read(),m=read();
		init();
		for(i=2;i<=n;++i){
			x=read(),y=read();
			addeg(x,y);
			addeg(y,x);
		}
		Solve();
	}
	return 0;
}
/*





*/

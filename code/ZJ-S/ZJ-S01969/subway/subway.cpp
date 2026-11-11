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
const int kMaxN=505,kMaxM=5e5+5,kMaxD=25,kMaxQ=1e5+5;
const ll inf=1e18;
int n,m,d;
ll w[kMaxM];
vector<int> bln[kMaxM];
int sz[kMaxN];
vector<int> vec[kMaxN],cst[kMaxN];
struct D{
	int xb;
	ll w;
	inline bool friend operator<(D x,D y){
		return x.w>y.w;
	}
};
priority_queue<D> pq;
bool vst[kMaxM];
ll dst[kMaxM];
inline void Solve(int st){
	int i,u,v;
	ll tmp=0;
	for(i=1;i<=m;++i) vst[i]=false,dst[i]=inf;
	while(!pq.empty()) pq.pop();
	pq.push((D){st,0});
	dst[st]=0;
	while(!pq.empty()){
		u=pq.top().xb;
		pq.pop();
		if(vst[u]) continue;
		vst[u]=true;
		for(int k:bln[u]){
			for(i=0;i<sz[k];++i){
				if(vec[k][i]==u){
					tmp=cst[k][i];
					break;
				}
			}
			for(i=0;i<sz[k];++i){
				v=vec[k][i];
				if(v==u) continue;
				if(dst[v]>dst[u]+tmp+cst[k][i]){
					dst[v]=dst[u]+tmp+cst[k][i];
					pq.push((D){v,dst[v]});
				}
			}
		}
	}return;
}
struct Q{
	int x,y,xb;
	inline bool friend operator<(Q a,Q b){
		return a.x<b.x;
	}
}qsn[kMaxQ];
ll op[kMaxQ];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int id,T,i,j,x,y;
	ll t;
	id=read(),n=read(),m=read(),d=read(),T=read();
	for(i=1;i<=m;++i) w[i]=read();
	for(i=1;i<=n;++i){
		sz[i]=read();
		for(j=1;j<=sz[i];++j){
			x=read(),t=read();
			bln[x].push_back(i);
			vec[i].push_back(x);
			cst[i].push_back(t);
		}
	}
	for(i=1;i<=T;++i){
		x=read(),y=read();
		if(x>y) swap(x,y);
		qsn[i].x=x;
		qsn[i].y=y;
		qsn[i].xb=i;
	}
	sort(qsn+1,qsn+T+1);
	for(i=1;i<=T;++i){
		if(qsn[i].x!=qsn[i-1].x)
			Solve(qsn[i].x);
		op[qsn[i].xb]=(w[qsn[i].x]+w[qsn[i].y]+dst[qsn[i].y]);
	}
	for(i=1;i<=T;++i) write(op[i]);
	return 0;
}
/*





*/

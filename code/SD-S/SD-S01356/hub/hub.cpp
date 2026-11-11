#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(auto i=(a);i<=(b);i++)
#define REP(i,a,b) for(auto i=(a);i>=(b);i--)
#define FORK(i,a,b,k) for(auto i=(a);i<=(b);i+=(k))
#define REPK(i,a,b,k) for(auto i=(a);i>=(b);i-=(k))
#define fi first
#define se second
#define gc getchar()
#define pc putchar
#define pln pc(10);
#define eb emplace_back
#define pb push_back
#define mkpr make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
template<class T>
void ckmx(T& a,T b){
	a=max(a,b);
}
template<class T>
void ckmn(T& a,T b){
	a=min(a,b);
}
template<class T>
void read(T& x){
	x=0;
	int f=1;
	char ch=gc;
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=gc;
	}
	x*=f;
}
void io(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
const int maxn=4005;
int n,k;
vi g[maxn];
int f[maxn][maxn][3][2];
int siz[maxn];
// u 为根的子树，选择了 i 个点，当前连通块数量，u 本身是否被选择  
// 此时，u 的最优方案是什么样的（ >0 表示 u 的，距离 u 最短的被选择点的距离 +1，<0 表示距离 u 的距离最远的不合法点到 u 的距离 +1）  
int lim;// 可接受的最大距离 
int upd(int& a,int b){// 仅在 u 不选择的情况下生效 
	if(a>0){
		if(b>0){
			ckmn(a,b);
		}
	}else{
		if(b>0){
			a=b;
		}else{
			if(b>a){
				a=b;// 减少最远不合法的距离 
			}
		}
	}
}
int get(int a,int b){
	// a,b 分别为两个子树状态，合并是多少？  
	if(!a)return b;
	if(!b)return a;
	if(a<b)swap(a,b);// a>b
	if(b<0){// b 不合法 
		if(a>0){// a 合法 
			if(a+abs(b)<=lim){
				return a;
			}
			return b;
		}else{
			return min(a,b);
		}
	}else{
		return b;
	}
}
void dfs(int u,int _fa){
	vi sons;
	siz[u]=1;
	for(int& v:g[u]){
		if(v==_fa)continue;
		dfs(v,u);
		sons.eb(v);
		siz[u]+=siz[v];
	}
	{
		FOR(chose,0,siz[u]){
			FOR(ltk,0,2){
				FOR(b,0,1){
					f[u][chose][ltk][b]=-1e9;
				}
			}
		}
	}
	{
		// u 自己被选择
		bool g[2][siz[u]+1][3];// 遍历子树 / 选择点数 / 连通块数量，是否可行？ 
		FOR(b,0,1){
			FOR(i,0,siz[u]){
				FOR(j,0,2){
					g[b][i][j]=0;
				}
			}
		}
		g[0][0][1]=1;
		bool b=0;
		int totsiz=0;
		for(int v:sons){
			FOR(cursiz,0,totsiz){
				FOR(curltk,0,2){
					if(g[b][cursiz][curltk]==0)continue;
					FOR(subsiz,0,siz[v]){
						FOR(subltk,0,2){
							int _newltk=curltk+subltk;
							if(f[v][subsiz][subltk][1]>=-lim){// 保证子树内最远不合法点到 u 的距离不超过限制 
								// v 本身被选择
								int newltk=_newltk-1;
								if(newltk>=0&&newltk<=2){
									g[b^1][cursiz+subsiz][newltk]=1;
								}
							}
							if(f[v][subsiz][subltk][0]>=-lim){
								// v 不被选择
								int newltk=_newltk;
								if(newltk<=2){
									g[b^1][cursiz+subsiz][newltk]=1;
								} 
							}
						}
					}
					g[b][cursiz][curltk]=0;
				}
			}
			b^=1;
			totsiz+=siz[v];
		}
		FOR(chose,0,siz[u]){
			FOR(ltk,0,2){
				if(!g[b][chose][ltk])continue;
				f[u][chose+1][ltk][1]=1;
		//		printf("f[%d][%d][%d][1] OK\n",u,chose+1,ltk);
				// 注意 u 本身也算  
			}
		}
	}
	{
		// u 不被选择 
		int g[2][siz[u]+1][3];// 遍历子树 / 选择个数 / 连通块个数，此时的子树答案（定义为到达 u 的距离） 
		FOR(b,0,1){
			FOR(i,0,siz[u]){
				FOR(ltk,0,2){
					g[b][i][ltk]=-1e9;
				}
			}
		}
		bool b=0;
		g[b][0][0]=0;
		int totsiz=0;
		for(int v:sons){
			FOR(cursiz,0,totsiz){
				FOR(curltk,0,2){
					int curdp=g[b][cursiz][curltk];
					FOR(subsiz,0,siz[v]){
						FOR(subltk,0,2-curltk){
							FOR(vchose,0,1){
								int subdp=f[v][subsiz][subltk][vchose];
								int nxtdp=get(curdp,subdp);
								
								upd(g[b^1][cursiz+subsiz][curltk+subltk],nxtdp);
								/*if(u==3&&curltk==0&&subsiz==1&&subltk==1&&vchose==1){
									printf("subdp %d curdp %d nxtdp %d updmx %d\n",subdp,curdp,nxtdp,g[b^1][cursiz+subsiz][curltk+subltk]);
								}*/
							}
						}
					}
					g[b][cursiz][curltk]=-1e9;
				}
			}
			b^=1;
			totsiz+=siz[v];
		}
		FOR(chose,0,siz[u]){
			FOR(ltk,0,2){
				int cur=g[b][chose][ltk];
				if(cur>0){
					// 子树内最近被选择距离 u = cur
					if(cur<=lim){
						cur++;
					}else{
						cur=-1;
					}
				}else{
					cur--;
				}
				f[u][chose][ltk][0]=cur;
			}
		}
	}
}
bool chk(){
	dfs(1,0);
	FOR(ltk,0,2){
		FOR(b,0,1){
		//	printf("f[1][k][%d][%d] = %d\n",ltk,b,f[1][k][ltk][b]);
			if(f[1][k][ltk][b]>0){
				return 1;
			}
		}
		
	}
	
	return 0;
}
void clear(){
	FOR(i,1,n){
		g[i].clear();
	}
}
void solve(int testid){
	read(n);
	read(k);
	FOR(i,1,n-1){
		int u,v;
		read(u);
		read(v);
		g[u].eb(v);
		g[v].eb(u);
	}
//	lim=0;
//	chk();
//lim=1;
//	chk();
//	printf("f = %d\n",f[3][1][1][0]);
//	return; 
	int efl=0,efr=n;
	int ok=n;
	while(efl<=efr){
		lim=(efl+efr>>1);
		if(chk()){
			ok=lim;
			efr=lim-1;
		}else{
			efl=lim+1;
		}
	}
	printf("%d\n",ok);
	// clear
	clear();
}
int main(){
	io();
	int c;
	read(c);
	int T;
	read(T);
	FOR(_,1,T){
		solve(c);
	}
	return 0;
}


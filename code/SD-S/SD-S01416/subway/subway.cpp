#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define ft first
#define sd second
#define ll long long
#define Pli pair<ll,int>
#define Pii pair<int,int>
#define gc getchar
#define pc putchar
using namespace std;
template <typename _T>
inline void read(_T &x){x=0;char ch=gc();for(;ch<'0'||ch>'9';ch=gc());for(;ch>='0'&&ch<='9';ch=gc())x=(x<<3)+(x<<1)+(ch^48);}
inline void write(ll x){short buf[20],top=0;for(;x;x/=10)buf[++top]=x-x/10*10;for(;top;--top)pc(buf[top]+48);}
const ll N=502,M=500002,MAXM=2000002,INF=1e18;
ll tp,n,m,k,q,a[M],t[N][N],x,y;
int pre[N],deg[M<<1],u[MAXM],v[MAXM],w[MAXM],tot=0;
Pii tu[MAXM];
ll dis[1002][1002],f[M<<1];
bool vis[M<<1];
vector<int> vt[20502];
priority_queue<Pli,vector<Pli>,greater<Pli> > qe;
queue<int> QE;
inline void add(int U,int V,int W){u[++tot]=U,v[tot]=V,w[tot]=W,deg[U]++;}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(tp),read(n),read(m),read(k),read(q);
	for(int i=1;i<=m;++i)
		read(a[i]);
	if(tp>=12&&tp<=15){
		ll tim;
		for(int i=1;i<=n;++i){
			read(x);
			for(int j=1;j<=x;++j){
				read(y),read(tim);
				vt[m+i].emplace_back(y);
				vt[y].emplace_back(m+i);
			}
		}
		for(;q--;){
			read(x),read(y);
			for(int i=1;i<=n+m;++i)
				f[i]=-1;
			for(;!QE.empty();QE.pop());
			f[x]=0;
			QE.push(x);
			for(;!QE.empty();){
				int now=QE.front();
				QE.pop();
				if(now==y)
					break;
				for(int i=0;i<vt[now].size();++i){
					int v=vt[now][i];
					if(f[v]==-1){
						f[v]=f[now]+tim;
						QE.push(v);
					}
				}
			}
			write(a[x]+a[y]+f[y]),pc('\n');
		}
		return 0;
	}
	pre[0]=m;
	for(int i=1;i<=n;++i){
		read(x);
		pre[i]=pre[i-1]+x;
		for(int j=1,v,w,lst;j<=x;++j){
			read(v),read(w);
			add(v,pre[i-1]+j,w),add(pre[i-1]+j,v,w);
			if(j>1)
				add(lst,pre[i-1]+j,0),add(pre[i-1]+j,lst,0);
			lst=pre[i-1]+j;
		}
	}
	for(int i=1;i<=pre[n]+1;++i)
		deg[i]+=deg[i-1];
	for(int i=1;i<=tot;++i)
		tu[--deg[u[i]]]={v[i],w[i]};
	for(int i=1;i<=m;++i){
		for(int j=1;j<=pre[n];++j)
			f[j]=INF,vis[j]=0;
		f[i]=0;
		qe.push({0,i});
		for(;!qe.empty();){
			int now=qe.top().sd;
			qe.pop();
			if(vis[now])
				continue;
			vis[now]=1;
			for(int j=deg[now];j<deg[now+1];++j){
				int v=tu[j].ft,w=tu[j].sd;
				if(f[v]>f[now]+w){
					f[v]=f[now]+w;
					qe.push({f[v],v});
				}
			}
		}
		for(int j=1;j<=m;++j)
			dis[i][j]=f[j];
	}
	for(;q--;){
		read(x),read(y);
		write(a[x]+a[y]+dis[x][y]),pc('\n');
	}
	return 0;
}

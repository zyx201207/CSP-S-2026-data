#include<bits/stdc++.h>
using namespace std;namespace hxyt1{
//#define int ll
#define ll long long
#define U unsigned
#define file(s) freopen(#s ".in","r",stdin),freopen(#s ".out","w",stdout)
#define rad read<int>
#define gc getchar
template<class T>T read(){char c;bool f=0;T x=0;for(;!isdigit(c=gc());f|=c=='-');for(;isdigit(c);x=x*10+c-48,c=gc());return f?-x:x;}
const int N=1005;int nn,n,Q,tos[N],cnt,act[N],bel[500005],fak[500005];vector<int>t[N],a[N];//1~nn:subway station
ll dis[N][N];
struct Edge{
	int v;ll w;
	bool operator<(const Edge&o)const{return w>o.w;}
};vector<Edge>e[N];
void add(int u,int v,ll w){e[u].push_back({v,w});}
void dij(ll *dis,int s){
	priority_queue<Edge>pq;
	pq.push({s,dis[s]=0});
	for(;pq.size();){
		Edge u=pq.top();pq.pop();
		if(dis[u.v]!=u.w)continue;
		for(auto&x:e[u.v]){
			int v=x.v;ll wgt=x.w;
			if(dis[v]>u.w+wgt)pq.push({v,dis[v]=u.w+wgt});
		}
	}
}
void hxyt(){
	file(subway);
	rad(),nn=rad(),n=rad(),rad(),Q=rad();
	for(int i=1;i<=n;i++)tos[i]=rad();
	for(int i=1;i<=nn;i++){
		int x=rad();
		for(int v,w;x--;)v=rad(),w=rad(),a[v].push_back(i),t[v].push_back(w);
	}
	for(int i=1;i<=n;i++){
		if(a[i].size()>=2){
			if(!fak[i])act[++cnt]=i,
				fak[i]=cnt;
			for(int j=0;j<a[i].size();j++){
				add(a[i][j],fak[i]+nn,t[i][j]);
				add(fak[i]+nn,a[i][j],t[i][j]);
			}
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=nn+cnt;i++)dij(dis[i],i);
	for(int x,y;Q--;){
		x=rad(),y=rad();ll ans=0;
		if(fak[x]){
			if(fak[y])ans=dis[fak[x]+nn][fak[y]+nn];
			else ans=dis[fak[x]+nn][a[y][0]]+t[y][0];
		}
		else if(fak[y])ans=dis[fak[y]+nn][a[x][0]]+t[x][0];
		else ans=dis[a[y][0]][a[x][0]]+t[x][0]+t[y][0];
		printf("%lld\n",ans+tos[x]+tos[y]);
	}
}}signed main(){return hxyt1::hxyt(),0;}


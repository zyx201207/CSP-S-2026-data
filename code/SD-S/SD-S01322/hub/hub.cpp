#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s = 0;char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch))s = (s<<1)+(s<<3)+ch-'0',ch = getchar();
	return s; 
}
const int N = 1e6+5;
struct E{
	int v,nt;
}e[2*N];
int tc,T,n,m,hd[N],ect = 2,dis[N],ct,vq[N],rv,mv[N],res[N];
vector<int> ds[N];
void add(int u,int v){
	e[ect] = E{v,hd[u]};
	hd[u] = ect++;
}
bool vis[N];
void dfs(int p){
	vis[p] = 1;
	if(dis[p]>dis[rv])rv = p;
	for(int i = hd[p];i;i = e[i].nt){
		if(vis[e[i].v])continue;
		dis[e[i].v] = dis[p]+1;
		dfs(e[i].v);
	}
}
void dfs2(int p){
	vis[p] = 1;
	dis[p] = 0;
	for(int i = hd[p];i;i = e[i].nt){
		if(vis[e[i].v])continue;
		dfs2(e[i].v);
		if(ds[rv].size()<=dis[e[i].v])
			ds[rv].emplace_back(0);
		ds[rv][dis[e[i].v]]++;
		dis[p] = max(dis[p],dis[e[i].v]+1);
	}
}
int gtnxt(int p){
	dis[p] = rv = 0;
	dfs(p);
	return rv;
}
bool ck(int d){
	int pr = 0,c = 0,pv = 0;
	for(int i = 1;i<ct;i++){
		pv = max(pv,i-1+mv[i]);
		pr = max(pr,min(i,i+mv[i]-d));
		if(d<(int)ds[i].size())
			c+=ds[i][d];
		if(pv<=2*d)res[i] = 1;
		else res[i] = c+pr-d;
	}
	pv = c = 0;
	pr = ct;
	int pres = 0;
	for(int i = ct;i>1;i--){
		pv = max(pv,ct-i+mv[i]);
		pr = min(pr,max(i,i-mv[i]+d));
		if(d<(int)ds[i].size())
			c+=ds[i][d];
		if(pv<=2*d)pres = 1;
		else pres = c+ct-d-pr+1;
//		cerr << pres << ' ' << res[i-1] << ' ' << d << "\n";
		if(pres+res[i-1]<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	tc = read();T = read();
	while(T--){
		n = read();m = read();
		ect = 2;
		memset(hd,0,4*(n+1));
		for(int i = 1,u,v;i<n;i++){
			u = read();v = read();
			add(u,v);add(v,u);
		}
		memset(vis,0,n+1);
		int u = gtnxt(1);
		memset(vis,0,n+1);
		int v = gtnxt(u);
		memset(vis,0,n+1);
		vq[(ct = 1)] = v;
		vis[v] = 1;
		int p = v;
		while(p!=u){
			for(int i = hd[p];i;i = e[i].nt){
				if(dis[e[i].v]==dis[p]-1){
					p = e[i].v;
					break;
				}
			}
			vq[++ct] = p;
			vis[p] = 1;
		}
		for(int i = 1;i<=ct;i++){
			rv = i;
			ds[i].clear();
			dfs2(vq[i]);
			for(int j = (int)ds[i].size()-1;j>0;j--)
				ds[i][j-1]+=ds[i][j];
			mv[i] = dis[vq[i]];
		}
		int l = 0,r = n-1,mid;
		while(l<r){
			mid = (l+r)>>1;
			if(ck(mid))r = mid;
			else l = mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}


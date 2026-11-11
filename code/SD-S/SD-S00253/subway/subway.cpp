#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pir pair<int,pair<int,int> >
using namespace std;
const int M=5e3+5;
const int K=1e7+6;
int c,n,m,d,t;
int val[M];
int a[M],cnt;
int ans[M][M];
vector<pii> vis[M];
map<pii,int> h,dis;
map<pii,int> mp,old;
priority_queue<pir,vector<pir>,greater<pir> > q;
struct node{
	pii to;
	int nxt,w;
}e[K];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while('0'<=ch && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void add(pii u,pii v,int w){
	e[++cnt].nxt=h[u];
	e[cnt].to=v;
	e[cnt].w=w;
	h[u]=cnt;
}
inline void dij(int s){
	mp.clear();
	for (auto i:vis[s]){
		int v=i.first,T=i.second;
		dis[pii(s,v)]=T;
		q.push(pir(T,pii(s,v)));
	}
	while(!q.empty()){
		auto x=q.top();
		q.pop();
		pii u=x.second;
		if (mp[u]) continue;
		mp[u]=1;
		for (int i=h[u];i;i=e[i].nxt){
			pii v=e[i].to;
			if (dis[u]+e[i].w<dis[v]){
				dis[v]=dis[u]+e[i].w;
				q.push(pir(dis[v],v));
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read();
	d=read(),t=read();
	for (int i=1;i<=m;i++) val[i]=read();
	for (int i=1;i<=n;i++){
		int k; k=read();
		for (int j=1,tm;j<=k;j++){
			a[j]=read(),tm=read();
			if (j>=2){
				add(pii(a[j],i),pii(a[j-1],i),0);
				add(pii(a[j-1],i),pii(a[j],i),0);
			}
			old[pii(a[j],i)]=1e9;
			if (!vis[a[j]].empty()){
				for (auto z:vis[a[j]]){
					int v=z.first,T=z.second; 
					add(pii(a[j],i),pii(a[j],v),tm+T);
					add(pii(a[j],v),pii(a[j],i),tm+T);
				}
			}
			vis[a[j]].push_back(pii(i,tm));
		}
	}
	memset(ans,0x3f,sizeof(ans));
	for (int i=1;i<=m;i++){
		dis=old;  dij(i);
		for (int j=1;j<=m;j++){
			if (i==j) continue;
			for (auto o:vis[j]){
				int z=o.first,T=o.second;
				ans[i][j]=min(ans[i][j],dis[pii(j,z)]+T);
			}
			ans[i][j]+=val[i]+val[j];
		}
	}
	while(t--){
		int x,y;
		x=read(),y=read();
		printf("%lld\n",ans[x][y]);
	}
	return 0;
}

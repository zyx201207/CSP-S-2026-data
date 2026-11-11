#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,h[500010],cnt;
long long dis[500010],w[500010];
map<pair<int,int>,long long>ans;
struct Edge{
	int sub,tu,tv,v,ne;
	Edge(){}
	Edge(int xx,int yy,int zz,int ww,int tt){
		sub=xx,tu=yy,tv=zz,v=ww,ne=tt;
	}
	void print(){
		printf("%d %d %d %d\n",v,sub,tu,tv);
	}
}e[5000010];
struct disp{
	int sub,p,dis;
	Pd(){}
	Pd(int xx,int yy,int zz){
		sub=xx,p=yy,dis=zz;
	}
	bool operator<(const disp x)const{
		return dis<x.dis;
	}
};
void add(int xx,int yy,int zz,int ww,int tt){
	e[++cnt]={tt,zz,ww,yy,h[xx]};
	h[xx]=cnt;
	return;
}
long long dijkstra(int x,int y){
	priority_queue<disp>pq;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[x]=0;
	pq.push({0,x,0});
	while(!pq.empty()){
		disp t=pq.top();
		pq.pop();
		for(int i=h[t.p];i!=-1;i=e[i].ne){
			if(t.sub!=e[i].sub){
				if(dis[e[i].v]>dis[t.p]+e[i].tu+e[i].tv){
					dis[e[i].v]=dis[t.p]+e[i].tu+e[i].tv;
					pq.push({e[i].sub,e[i].v,dis[e[i].v]});
				}
			}
			else{
				if(dis[e[i].v]>dis[t.p]-e[i].tu+e[i].tv){
					dis[e[i].v]=dis[t.p]-e[i].tu+e[i].tv;
					pq.push({e[i].sub,e[i].v,dis[e[i].v]});
				}
			}
		}
	}
	return dis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof(h));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k,a1,a2,t1,t2;
		scanf("%d%d%d",&k,&a1,&t1);
		for(int j=2;j<=k;j++){
			scanf("%d%d",&a2,&t2);
			add(a1,a2,t1,t2,i);
			add(a2,a1,t2,t1,i);
		}
	}
	for(int i=1;i<=q;i++){
		int st,ed;
		scanf("%d%d",&st,&ed);
		printf("%lld\n",w[st]+dijkstra(st,ed)+w[ed]);
	}
	return 0;
}

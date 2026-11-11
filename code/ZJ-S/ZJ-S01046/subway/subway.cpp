#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
inline ll read(){
    int c,w=1;
    ll ret=0;
    while((c=getchar())>'9'||c<'0') w=(c=='-'?-1:1);
    ret=c-48;
    while((c=getchar())<='9'&&c>='0') ret=ret*10+c-48;
    return w*ret;
}
bool start;
int const maxn=505,maxq=1e5+5,maxm=5e5+5,maxk=5e5+5;
ll const inf=1e18;

int ck=0;
int h[maxk+maxn];
struct node{
    ll v,w,nxt;
}e[(40000005)];

void add(int u,int v,int w){
    e[++ck]={v,w,h[u]};
    h[u]=ck;
}
int p;
int c,n,m,d,q;
int a[maxk],t[maxk],ww[maxk];

ll dis[maxk+maxn];
bool vis[maxn+maxk];
ll d2[3605][3605];
struct info{
    int u;
    ll W;
    bool operator<(const info &x) const{
        return W>x.W;
    }
};
priority_queue<info> pq;
void dij(int S,int T){
    for(int i=1;i<=p;i++) dis[i]=inf,vis[i]=0;
    dis[S]=0;
    pq.push({S,0});
    while(!pq.empty()){
        int u=pq.top().u;
        pq.pop();
        if(u==T) break;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=h[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w){
                dis[v]=dis[u]+e[i].w;
             //   cout<<u<<' '<<v<<' '<<e[i].w<<' '<<dis[v]<<'\n';
                pq.push({v,dis[v]});
            }
        }
    }
	while(!pq.empty()) pq.pop();
}

namespace task2{
	
	void dij2(int S){
		for(int i=1;i<=p;i++) d2[S][i]=inf,vis[i]=0;
	    d2[S][S]=0;
	    pq.push({S,0});
	    while(!pq.empty()){
	        int u=pq.top().u;
	        pq.pop();
	      //  if(u==T) break;
	        if(vis[u]) continue;
	        vis[u]=1;
	        for(int i=h[u];i;i=e[i].nxt){
	            int v=e[i].v;
	            if(d2[S][v]>d2[S][u]+e[i].w){
	                d2[S][v]=d2[S][u]+e[i].w;
	             //   cout<<u<<' '<<v<<' '<<e[i].w<<' '<<dis[v]<<'\n';
	                pq.push({v,d2[S][v]});
	            }
	        }
	    }
	}
	
	void pre(){
		
		for(int i=1;i<=m;i++) dij2(i);
		
	}
	
};

//namespace task3{
//	int cp=0;
//	int Id[20105];
//	int x[maxn],y[maxn];
//	void dij3(int S){
//		for(int i=1;i<=p;i++) d2[S][i]=inf,vis[i]=0;
//	    d2[S][S]=0;
//	    pq.push({S,0});
//	    while(!pq.empty()){
//	        int u=pq.top().u;
//	        pq.pop();
//	      //  if(u==T) break;
//	        if(vis[u]) continue;
//	        vis[u]=1;
//	        for(int i=h[u];i;i=e[i].nxt){
//	            int v=e[i].v;
//	            if(d2[S][v]>d2[S][u]+e[i].w){
//	                d2[S][v]=d2[S][u]+e[i].w;
//	             //   cout<<u<<' '<<v<<' '<<e[i].w<<' '<<dis[v]<<'\n';
//	                pq.push({v,d2[S][v]});
//	            }
//	        }
//	    }
//	}
//	
//	void pre(){
//		for(int i=1;i<=q;i++){
//			if(!Id[x[i]]) Id[x[i]]=++cp;
//			if(!Id[y[i]]) Id[y[i]]=++cp;
//		}
//		for(int i=1;i<=)
//	}
//	
//};

bool eddd;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    p=m;
    //i 2i 3i
    //地铁口 站厅 站台
    for(int i=1;i<=m;i++){
        ww[i]=read();
    }
    for(int i=1,k;i<=n;i++){
        k=read();
        p++;
        for(int j=1;j<=k;j++){
            a[j]=read(),t[j]=read();
            add(a[j],p,t[j]);
            add(p,a[j],t[j]);
        }
    }
    if(m<=1000){
    	task2::pre();
    	for(int i=1,x,y;i<=q;i++){
        x=read(),y=read();
	        cout<<d2[x][y]+ww[x]+ww[y]<<'\n';
	    }
    	return 0;
	}
//	if(12<=c&&c<=15){
//		for(int i=1;i<=q;i++){
//	        task3::x[i]=read();
//	        task3::y[i]=read();
//	    }
//	    task3::pre();
//	}
    for(int i=1,x,y;i<=q;i++){
        x=read(),y=read();
        dij(x,y);
        cout<<dis[y]+ww[x]+ww[y]<<'\n';
    }
   // printf("%.2lf",((&start)-(&eddd))/1024.0/1024.0);

    return 0;
}
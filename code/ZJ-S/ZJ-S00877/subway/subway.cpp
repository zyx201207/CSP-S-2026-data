#include<bits/stdc++.h>
#define int long long
#define FL(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
inline int read(){
	int sum=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)){sum=sum*10+c-'0';c=getchar();}
	return sum*f;
}
const int N=505;
const int M=6e5+5;
struct node{
	int y,v;
	bool operator < (const node& a) const{
		return a.v<v;
	}
};
int c,n,m,d,q;
int w[M];
int k[N],id[N];
int dis[N][N];
vector<node> G[M],G2[N];
priority_queue<node> pq;
int vis[N];
void dij(int S){
	while(!pq.empty()) pq.pop();
	pq.push({S,0});
	FL(i,1,n) if(i!=S) dis[S][i]=1e18;
	FL(i,1,n) vis[i]=0;
	while(!pq.empty()){
		int x=pq.top().y;pq.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto i : G2[x]){
			int y=i.y,v=i.v;
			if(!vis[y]&&dis[S][x]+v<dis[S][y]){
				dis[S][y]=dis[S][x]+v;
				pq.push({y,dis[S][y]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	FL(i,1,m) w[i]=read();
	FL(i,1,n) id[i]=i+m; 
	FL(i,1,n){
		k[i]=read();
		FL(j,1,k[i]){
			int aj=read(),tj=read();
			G[id[i]].push_back(node{aj,tj});
			G[aj].push_back(node{id[i],tj});
		}
	}
	FL(i,1,n) FL(j,1,n) if(i!=j) dis[i][j]=1e18;
	FL(i,1,n){
		for(auto p1 : G[id[i]]){
			for(auto p2 : G[p1.y]){
				if(p2.y==i) continue;
				int j=p2.y-m;
				int len=p1.v+p2.v;
				if(len<dis[i][j])
					dis[i][j]=dis[j][i]=len;
			}
		}
	}
	FL(i,1,n) FL(j,1,n) if(dis[i][j]!=1e18){
		G2[i].push_back({j,dis[i][j]});
	}
	FL(i,1,n) dij(i);
	while(q--){
		int x=read(),y=read(),ans=1e18;
		for(auto p1 : G[x]){
			for(auto p2 : G[y]){
				int px=p1.y-m,py=p2.y-m;
				int val=dis[px][py]+p1.v+p2.v;
				if(val<ans) ans=val;
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

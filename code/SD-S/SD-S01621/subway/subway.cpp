#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll M=5e5+10,N=510;
ll c,n,m,d,q,w[M],k[M],T,dis[M];
bool sta[M][N],gone[M];
struct node{
	ll u,dis;
	operator>(const node &x)const{
		return dis>x.dis;
	}
};
struct edge{
	ll u,len;
};
vector<edge>g[M];
inline void dijkstra(ll s){
	priority_queue<node,vector<node>,greater<node>>q;
	q.push({s,0});
	memset(dis,0x3f,sizeof(dis));
	memset(gone,false,sizeof(gone));
	dis[s]=0;
	while(!q.empty()){
		ll x=q.top().u;
		q.pop();
		if(gone[x])
			continue;
		gone[x]=true;
		for(auto i:g[x])
			if(dis[i.u]>dis[x]+i.len){
				dis[i.u]=dis[x]+i.len;
				q.push({i.u,dis[i.u]});
			}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(ll j=1;j<=k[i];j++){
			ll a,tr;
			scanf("%lld%lld",&a,&T);
			sta[a][i]=true;
		}
	}
	for(ll i=1;i<=m;i++)
		for(ll j=1;j<=n;j++)
			if(sta[i][j]){
				g[i].push_back({m+j,T});
				g[m+j].push_back({i,T});
			}
	while(q--){
		ll x,y,xs=0,ys=0,begx,begy,answ,ans=0;
		scanf("%lld%lld",&x,&y);
		for(ll i=1;i<=n;i++){
			xs+=sta[x][i];
			ys+=sta[y][i];
			if(sta[x][i])
				begx=i;
			if(sta[y][i])
				begy=i;
		}
		if(xs>1)
			dijkstra(x);
		else{
			ans+=T;
			dijkstra(begx);
		}
		if(ys>1)
			answ=y;
		else{
			answ=begy;
			ans+=T;
		}
		printf("%lld\n",w[x]+w[y]+dis[ans]+ans);
	}
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//using ll=long long;
//const ll M=5e5+10,N=510;
//ll c,n,m,d,q,w[M],k[M],T,dis[M],trans[N][N];
//bool sta[M][N],gone[M];
//struct node{
//	ll u,dis;
//	operator>(const node &x)const{
//		return dis>x.dis;
//	}
//};
//struct edge{
//	ll u,len;
//};
//vector<edge>g[M];
//inline void dijkstra(ll s){
//	priority_queue<node,vector<node>,greater<node>>q;
//	q.push({s,0});
//	memset(dis,0x3f,sizeof(dis));
//	memset(gone,false,sizeof(gone));
//	dis[s]=0;
//	while(!q.empty()){
//		ll x=q.top().u;
//		q.pop();
//		if(gone[x])
//			continue;
//		gone[x]=true;
//		for(auto i:g[x])
//			if(dis[i.u]>dis[x]+i.len){
//				dis[i.u]=dis[x]+i.len;
//				q.push({i.u,dis[i.u]});
//			}
//	}
//}
//int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
//	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
//	for(ll i=1;i<=m;i++)
//		scanf("%lld",&w[i]);
//	for(ll i=1;i<=n;i++){
//		scanf("%lld",&k[i]);
//		
//		ll a1,a2,t1,t2;
//		scanf("%lld%lld%lld%lld",&a1,&a2,&t1,&t2);
//		g[a1].push_back({a2,0});
//		g[a2].push_back({a1,0});
//	}
//	for(ll i=1;i<=m;i++)
//		for(ll j=1;j<=n;j++)
//			if(sta[i][j]){
//				g[i].push_back({m+j,T});
//				g[m+j].push_back({i,T});
//			}
//	while(q--){
//		ll x,y,xs=0,ys=0,begx,begy,answ,ans=0;
//		scanf("%lld%lld",&x,&y);
//		for(ll i=1;i<=n;i++){
//			xs+=sta[x][i];
//			ys+=sta[y][i];
//			if(sta[x][i])
//				begx=i;
//			if(sta[y][i])
//				begy=i;
//		}
//		if(xs>1)
//			dijkstra(x);
//		else{
//			ans+=T;
//			dijkstra(begx);
//		}
//		if(ys>1)
//			answ=y;
//		else{
//			answ=begy;
//			ans+=T;
//		}
//		printf("%lld\n",w[x]+w[y]+dis[ans]+ans);
//	}
//	return 0;
//}

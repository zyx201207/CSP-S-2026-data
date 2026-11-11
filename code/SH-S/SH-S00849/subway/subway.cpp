#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+505,Q=1e5+5; 
struct edge{
	ll v,w;
};
struct pos{
	ll u,dis;
};
struct test{
	ll x,y,id;
	bool operator<(const test& b) const{
		return x<b.x;
	}
}ans[Q];
struct cmp{
	bool operator()(const pos& a,const pos& b)const{
		return a.dis>b.dis;
	}
};
ll c,n,m,d,q,dis[N],a[N][25],id;
ll t[N][25],x,y,k[N],u,v,cou[Q];
ll vis[N],w[N];
vector<edge> e[N];
priority_queue<pos,vector<pos>,cmp> que;
void dij(ll s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	que.push({s,0});
	dis[s]=0;
	while(!que.empty()){
		pos po=que.top();
		que.pop();
		vis[u]=1;
		ll u=po.u; 
		for(edge &pp:e[u]){
			int v=pp.v,w=pp.w;
			if(vis[v])continue;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				que.push({v,dis[v]});
			}
		}
	}
	
}
int main(){	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		//printf("--------\n");
		scanf("%lld",&k[i]);
		int u=i+m;
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			int v=a[i][j],w=t[i][j];
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}	
	}
	for(int r=1;r<=q;r++){
		scanf("%lld%lld",&x,&y);
		ans[r]={x,y,r};
	}
	sort(ans+1,ans+q+1);
	int r=1;ans[r-1]=ans[r];
	
	for(r=1;r<=q;){
		x=ans[r].x;
		dij(x);
		do{
			x=ans[r].x,y=ans[r].y,id=ans[r].id;
			cou[id]=dis[y]+w[x]+w[y];
			r++;
		}while(ans[r].x==ans[r-1].x);
	}
	for(int i=1;i<=q;i++)
		printf("%lld\n",cou[i]);
	return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

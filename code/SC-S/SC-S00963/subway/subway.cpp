#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxn=1e6+10;
struct Edge{
	ll v,w,pre;
}edge[maxn];
ll node=0,head[maxn];
void add_edge(ll u,ll v,ll w){
	edge[++node].v=v;
	edge[node].w=w;
	edge[node].pre=head[u];
	head[u]=node;
}
ll c,n,m,d,p,ww[maxn],u3[maxn],dis[maxn],vis[maxn];
void dj(ll s){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	priority_queue<pll,vector<pll>,greater<pll> > q;
	dis[s]=edge[s].w;
	q.push(make_pair(edge[s].w,s));
	while(q.size()){
		ll u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].pre){
			ll v=edge[i].v,w=edge[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	while(n--){
		memset(u3,0,sizeof u3);
		ll k;
		cin>>k;
		for(int i=1;i<=2*k-3;i++){
			cin>>u3[i];
			add_edge(u3[1],u3[1],u3[2]);
			add_edge(u3[i],u3[i+2],u3[i+3]);
			//add_edge(u3[i+2],u3[i],u3[i+3]);
		}
	}
	while(p--){
		ll s,js;
		cin>>s>>js;
		dj(s);
		cout<<dis[js]+ww[s]+ww[js]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
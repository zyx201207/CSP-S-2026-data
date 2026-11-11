#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<utility>
#include<cstring>
#define int long long
using namespace std;
const int N=2e4+5;
int c,n,m,d,q;
int w[N];
int k[N];
struct node{
	int v,w,nxt;
}g[600*N];
int head[600*N],num;
void add(int u,int v,int w){
	g[++num]=(node){v,w,head[u]};
	head[u]=num;
}
priority_queue<pair<int,int> > pq;
int dis[N],vis[N],v[N];
int cnt[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int w1;
			cin>>v[j]>>w1;
			if(j>1){
				add(v[j-1],v[j],0);
				add(v[j],v[j-1],0);
			}
			add(v[j],v[j]+m,w1);
			add(v[j]+m,v[j],w1);
		}
	}
	while(q--){
		while(!pq.empty()){
			pq.pop();
		}
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		int s,e;
		cin>>s>>e;
		s+=m;
		pq.push(make_pair(0,s));
		dis[s]=0;
		while(!pq.empty()){
			int x=pq.top().second;
			pq.pop();
			if(vis[x]){
				continue;
			}
			vis[x]=1;
			for(int i=head[x];i;i=g[i].nxt){
				if(dis[g[i].v]>dis[x]+g[i].w){
					dis[g[i].v]=dis[x]+g[i].w;
					pq.push(make_pair(-dis[g[i].v],g[i].v));
				}
			}
		}
		cout<<dis[e+m]+w[s]+w[e]<<"\n";
	}
	return 0;
}

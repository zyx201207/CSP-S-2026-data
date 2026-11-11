#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=5e2+10;
const int P=5e6+10;
typedef pair<int,int> PII;
int c,n,m,d,q,k[M],path[N];
int h[P],e[P],ne[P],w[P],idx=0;
int dis[P];
bool vis[P];
long long wc[N],T;
void add(int a,int b,int c){
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}
void dijkstra(int st){
	memset(dis,0x3f,sizeof dis);
	memset(vis,false,sizeof vis);
	priority_queue<PII,vector<PII>,greater<PII> >Q;
	dis[st]=0;
	vis[st]=true;
	Q.push({0,st});
	while(Q.size()){
		PII t=Q.top();
		Q.pop();
		int ver=t.second;
		if(vis[ver]){
			continue;
		}
		vis[ver]=true;
		for(int i=h[ver];i!=-1;i=ne[i]){
			int j=e[i];
			if(dis[j]>dis[ver]+w[i]){
				dis[j]=dis[ver]+w[i];
				Q.push({dis[j],j});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>wc[i];
	}
	memset(h,-1,sizeof h);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>path[j]>>T;
		}
		for(int u=1;u<k[i];u++){
			for(int v=u+1;v<=k[i];v++){
				add(u,v,1);
				add(v,u,1);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dijkstra(u);
		cout<<dis[v]<<'\n';
	}
	return 0;
}

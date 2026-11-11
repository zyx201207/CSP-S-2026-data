#include<bits/stdc++.h>
#define N 500010
#define M 1000010
using namespace std;
const int INF=1e9;
int c,n,m,d,q;
int a[N],dist[N];
int x[N],t[N];
bool st[N];
int h[N],w[M],ne[M],e[M],idx;
void add(int a,int b,int c){ e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++; }
void spfa(int s){
	for(int i=1;i<=m;i++) dist[i]=INF,st[i]=0;
	queue<int> q;
	q.push(s); st[s]=1; dist[s]=0;
	while(!q.empty()){
		int t=q.front(); q.pop(); st[t]=0;
		for(int i=h[t];~i;i=ne[i]){
			int j=e[i];
			if(dist[j]>dist[t]+w[i]){
				dist[j]=dist[t]+w[i];
				if(!st[j]) q.push(j),st[j]=1;
			}
		}
	}
}
void dijkstra(int s){
	for(int i=1;i<=m;i++) dist[i]=INF,st[i]=0;
	priority_queue<int,vector<int>,greater<int>> q;
	q.push(s); dist[s]=0;
	while(!q.empty()){
		int t=q.top(); q.pop();
		if(st[t]) continue;
		st[t]=1;
		for(int i=h[t];~i;i=ne[i]){
			int j=e[i];
			if(dist[j]>dist[t]+w[i]){
				dist[j]=dist[t]+w[i];
				q.push(j);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof h);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>x[j]>>t[j];
		for(int a1=1;a1<=k;a1++){
			for(int a2=1;a2<=k;a2++){
				if(a1==a2) continue;
				add(x[a1],x[a2],t[a1]+t[a2]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		spfa(x);
		cout<<dist[y]+a[x]+a[y]<<'\n';
	}
	return 0;
}

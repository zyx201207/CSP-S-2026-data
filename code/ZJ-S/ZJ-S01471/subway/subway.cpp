#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int> PII;
#define x first
#define y second
const int N=5e5+509;
long long g[N];
int h[N],idx=0;
vector<int> e,ne;
vector<long long> w;
void add(int a,int b,long long c){
	e.push_back(b);
	w.push_back(c);
	ne.push_back(h[a]);
	h[a]=idx++;
}
int c,n,m,d,q;
long long dist[N];
bool st[N];
long long dijkstra(int s,int tt){
	for(int i=1;i<=n+m;i++) dist[i]=1e18;
	memset(st,0,sizeof st);
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,s});
	dist[s]=0;
	while(q.size()){
		PII t=q.top();
		q.pop();
		if(st[t.y]) continue;
		st[t.y]=1;
		for(int i=h[t.y];i;i=ne[i]){
			int j=e[i];
			long long ww=w[i];
			if(dist[j]>dist[t.y]+ww){
				dist[j]=dist[t.y]+ww;
				if(!st[j]) q.push({dist[j],j});
			}
		}
	}
	return dist[tt];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>g[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			add(n+i,u,w);
			add(u,n+i,w);
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<dijkstra(s,t)+g[s]+g[t]<<endl;
	}
	return 0;
}

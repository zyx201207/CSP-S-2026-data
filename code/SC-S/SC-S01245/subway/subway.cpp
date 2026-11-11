#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e2+10;
const int M=2e4+10;
int c,n,m,d,q,dis[N*M],vis[N*M];
int e[2*M*N],h[N*M],ne[2*N*M],w[2*N*M],idx=1;
vector<int> p[N];
void add(int a,int b,int c){
	e[idx]=b;
	ne[idx]=h[a];
	w[idx]=c;
	h[a]=idx++;
}
void dij(int s){
	priority_queue<pair<int ,int > >q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	vis[s]=1;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		for(int i=h[x];i;i=ne[i]){
			int v=e[i];
			if(vis[v]) continue;
			vis[v]=1;
			if(dis[v]>dis[x]+w[i]){
				dis[v]=dis[x]+w[i];
				q.push({-dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		add(i,i+m,w);
		add(i+m,i,w);
	}
	for(int i=1;i<=n;i++){
		int k,o;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			add((i+1)*m+a,a+m,t);
			add(a+m,(i+1)*m+a,t);
			if(j==1) o=a;
			else{
				add((i+1)*m+a,(i+1)*m+o,0);
				add((i+1)*m+o,(i+1)*m+a,0);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]<<'\n';
//		for(int i=1;i<=m;i++) cout<<dis[i+m]<<'\n';
	}
	return 0;
}
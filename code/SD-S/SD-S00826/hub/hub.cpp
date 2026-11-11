#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=10010;
vector<int> g[N];
vector<int> a;

int c,T,p[N],dist[N][N];
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}

void bfs(int x){
	memset(dist,-1,sizeof(dist));
	queue<int> q;
	q.push(x);
	dist[x][x]=0;
	while(q.size()){
		int u=q.front();q.pop();
		for(int v:g[u]){
			if(dist[x][v]==-1||dist[x][v]>dist[x][u]+1){
				dist[x][v]=dist[x][u]+1;
				q.push(v);
			}
		}
	} 
}
void solve(){
	int n,k;
	cin>>n>>k;
	map<int,int> mp;
	mp.clear();
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		int pu=find(u),pv=find(v);
		p[pu]=pv;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int state=0;state<(1<<n);state++){
		a.clear();
		int cnt=0;
		for(int i=0;i<n;i++){
			if(state&(1<<i)){
				a.push_back(i+1); 
			}
		}
		for(int t:a){
			int pa=find(t);
			if(mp[pa]==0){
				cnt++;
				mp[pa]=1;
			}
		}
		if(cnt>2) continue;
	}
	int mx=0;
	for(int t:a){
		bfs(t);
	}
	for(int i:a){
		for(int j:a){
			if(i==j) continue;
			mx=max(mx,dist[i][j]);
		}
	}
	cout<<mx<<'\n';
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>T;
	while(T--){
		solve(); 
	} 
	
	
	return 0;
} 



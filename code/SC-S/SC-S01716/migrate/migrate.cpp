#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t;
int n,d,x[N],dis[5010][5010];
int cnt[5010][5010];
vector<int> g[N];
void add(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}
queue<int> q;
void bfs(int st){
	for(int i=1;i<=n;i++) dis[st][i]=-1,cnt[st][i]=0;
	dis[st][st]=0,cnt[st][st]=1;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(dis[st][v]==-1){
				dis[st][v]=dis[st][u]+1;
				cnt[st][v]++;
				q.push(v);
			}else if(dis[st][v]==dis[st][u]+1) cnt[st][v]++,q.push(v);
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<i;j++){
			if(x[i]-x[j]<=d){
				add(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(cnt[i][j]==2) res++;
		}
	}
	cout<<res<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c<=10){
		while(t--) solve();
	}else{
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			int xxx=d/(x[2]-x[1]);
			if(xxx>1) cout<<max(n-xxx-xxx+1,0ll)<<'\n';
			else cout<<0<<'\n';
		}
	}
	
}
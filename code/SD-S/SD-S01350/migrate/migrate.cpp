#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int,int>
#define fi first
#define se second
#define mkp make_pair
const int N=2e6+5;
const int INF=0x3f3f3f3f3f;
vector<int> edge[N];
int n,d,CASE;
int a[N];
int f[N],dist[N];
int vis[N];
priority_queue<pll,vector<pll>,greater<pll> > q;
void init(){
	for(int i=0;i<=n;i++){
		vis[i]=0,a[i]=0;
		f[i]=0,dist[i]=0;
		edge[i].clear();
	}
}
void bfs(int s){
	for(int i=0;i<=n;i++){
		f[i]=0;
		dist[i]=INF;
		vis[i]=0;
	}
	dist[s]=0;
	f[s]=1;
	q.push(mkp(0,s));
	while(!q.empty()){
		int x=q.top().se;
		q.pop();
		if(vis[x]){
			continue;
		}
		vis[x]=1;
		for(int y:edge[x]){
			if(dist[y]>dist[x]+1){
				dist[y]=dist[x]+1;
				f[y]=f[x];
				q.push(mkp(dist[y],y));
			}
			else if(dist[y]==dist[x]+1){
				f[y]+=f[x];
			}
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[j]-a[i])<=d){
				edge[i].push_back(j);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(f[j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	init(); 
}
void solvea(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=d/(a[2]-a[1]);
	int ans=0;
	for(int l=1;l<=n;l++){
		int r=l+2*k-1;
		if(r>l&&r>l+k&&r<=n){
			ans++;
		}
	}
	cout<<ans<<'\n';
	init();
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>CASE>>T;
	while(T--){
		if(CASE<=10){
			solve();
		}
		else{
			solvea();
		}
	}
	return 0;
}

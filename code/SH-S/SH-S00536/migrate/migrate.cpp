#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
const ll INF=0x3f3f3f3f;
const int N=2e6+5; 
ll a[N];
vector<int> g[N];
int dis[N],vis[N],cnt[N];
int n;
ll d;
queue<int> q;
void bfs(int st){
	for(int i=1;i<=n;i++){
		dis[i]=INF;
		vis[i]=0;
		cnt[i]=0;
	}
	while(!q.empty())q.pop();
	q.push(st);
	dis[st]=0;
	vis[st]=1;
	cnt[st]=1;
	while(!q.empty()){
		int u=q.front();
//		cout<<u<<"\n";
		q.pop();
		for(auto v:g[u]){
			if(dis[v]==dis[u]+1||dis[v]==INF)cnt[v]+=cnt[u];
			if(vis[v])continue;
			vis[v]=1;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
} 
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]-a[1]<=d&&a[n]-a[i]<=d)return 1;
	}
	return 0;
} 
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[i].clear();
	}	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				g[i].push_back(j);
				g[j].push_back(i);
//				cout<<i<<' '<<j<<"\n";
			}
			else{
				break;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<dis[j]<<" "<<cnt[j]<<"\n"; 
			if(cnt[j]==2)ans++;
		}
	}
	cout<<ans<<"\n";

}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
}


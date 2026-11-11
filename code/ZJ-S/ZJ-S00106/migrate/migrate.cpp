#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=1e6+5;
const int INF=1e18;
const int MOD=1e9+7;
int c,n,d,dis[N],x[N],vis[N],cnt[N],ans;
vector<int>g[N];
void bfs(int st){
	queue<int>q;
	for(int i=0;i<=n+1;i++){
		vis[i]=0;
		dis[i]=INF;
		cnt[i]=0;
	}
	dis[st]=0;
	cnt[st]=1;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}
			else if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
		}
	}
}
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=0;i<=n+1;i++)g[i].clear();
	for(int i=1;i<=n;i++)cin>>x[i];
	if(n>=(int)2e4){
		cout<<0<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(x[i]-x[j]<=d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
			else break;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(auto v:g[i]){
//			cout<<i<<" "<<v<<endl;
//		}
//	} 
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
		//	cout<<i<<" "<<j<<" "<<dis[j]<<" "<<cnt[j]<<endl;
			if(cnt[j]==2)ans++;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}

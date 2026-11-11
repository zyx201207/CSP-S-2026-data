#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+7,M=6010;
int c,t,n,cnt[M][M],dis[M][M];
ll a[N],d,ans;
vector<int> G[M];
inline void init(){
	for(int i=1;i<=n;i++){
		G[i].clear();
		for(int j=i+1;j<=n;j++) dis[i][j]=1e9,cnt[i][j]=0;
	}
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
bool vis[N];
inline void bfs(int st){
	while(!q.empty())q.pop();
	for(int i=st;i<=n;i++)vis[i]=0;
	dis[st][st]=0,cnt[st][st]=1,q.push({0,st});
	int u;
	while(!q.empty()){
		u=q.top().second,q.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int v:G[u]){
			if(dis[st][u]+1==dis[st][v]){
				cnt[st][v]+=cnt[st][u];
			}else if(dis[st][u]+1<dis[st][v]){
				dis[st][v]=dis[st][u]+1,cnt[st][v]=cnt[st][u],q.push({dis[st][v],v});
			}
		}
	}return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=6000){
			init();
			for(int i=1,p;i<n;i++){
				if(a[i]+d<a[i+1])continue;
				else if(a[i]+d>=a[n]) p=n;
				else p=upper_bound(a+i+1,a+n+1,a[i]+d)-a-1;
				for(int j=i+1;j<=p;j++)G[i].push_back(j);
			}
			for(int i=1;i<n;i++){
				bfs(i);
			}ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(cnt[i][j]==2) ans++;
				}
			}cout<<ans<<'\n';
			continue;
		}
		ll D=a[2]-a[1],len=d/D;
		if(len<2 || 2ll*len>1ll*n){
			cout<<0<<'\n';
			continue;
		}
		cout<<n-2*len+1<<'\n';
	}
	return 0;
}
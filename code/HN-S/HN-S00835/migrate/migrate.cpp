#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
const int N=1e6+5,M=5e3+5;
int c,n,d,x[N],dis[M][M],cnt[M][M],vis[M];
vector<int> g[N]; 
void bfs(int s){
	memset(vis,0,sizeof(vis));
	queue<int> q;q.push(s);
	vis[s]=1;dis[s][s]=0;cnt[s][s]=1;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(auto i:g[t]){
			if(dis[s][i]>dis[s][t]+1){
				dis[s][i]=dis[s][t]+1;
				cnt[s][i]=cnt[s][t];
				if(!vis[i]) q.push(i),vis[i]=1; 
			}else if(dis[s][i]==dis[s][t]+1){
				cnt[s][i]++;
			}
		}
	}
} 
void sol(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(c<=10){
		for(int i=1;i<=n;i++){
			g[i].clear();
			for(int j=1;j<=n;j++){
				dis[i][j]=1e18;
				cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d) break;
				g[i].pb(j);g[j].pb(i);
			}
		}
		for(int i=1;i<=n;i++) bfs(i);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";		
	}else if(c==11||c==12){
		if(d/(x[2]-x[1])<=1) cout<<0<<"\n";
		else cout<<max(0ll,n-(d/(x[2]-x[1])*2-1))<<"\n";
	}

}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;cin>>c>>T;
	while(T--) sol();
	return 0;
}



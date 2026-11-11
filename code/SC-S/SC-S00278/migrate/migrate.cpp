#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5010;
ll x[N];
ll dis[N][N];ll cnt[N][N];
vector<int> g[N];
struct Node{
	int u;
	ll dis;
	inline bool operator<(Node o)const {
		return dis<o.dis;
	}
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		int n;ll d; cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)g[i].clear();
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n&&x[j]-x[i]<=d;j++)
				g[i].push_back(j),g[j].push_back(i);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			queue<Node> q;
			q.push({i,dis[i][i]=0ll});
			cnt[i][i]=1;
			while(!q.empty()){
				Node cur=q.front();q.pop();
				int u=cur.u;ll d=cur.dis;
				if(d>dis[i][u]) continue;
				for(auto v:g[u]){
					if(dis[i][v]>1+d){
						q.push({v,dis[i][v]=1+d});
						cnt[i][v]=cnt[i][u];
					} else if(dis[i][v]==1+d)
						cnt[i][v]+=cnt[i][u];
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt[i][j]==2)ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=5e5+5,mod=998244353;
int c,n,m,d,q;
int w[N];
int k;
struct node{
	int v,w;
	bool operator <(const node a)const{
		return w>a.w;
	}
};
vector<node>g[505];
priority_queue<node>pq;
int dis[505];
bool vis[505];
int a,t;
int sum[505];
PII ttt[N][21];
int ooo[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	system("fc subway.out subway7.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a>>t;
			ttt[a][++ooo[a]]={i,t};
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=ooo[i];++j){
			for(int k=j+1;k<=ooo[i];++k){
				g[ttt[i][j].first].push_back({ttt[i][k].first,ttt[i][j].second+ttt[i][k].second});
				g[ttt[i][k].first].push_back({ttt[i][j].first,ttt[i][j].second+ttt[i][k].second});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;++i){
			vis[i]=0;
			dis[i]=0x3f3f3f3f3f3f3f3f;
		}
		for(int i=1;i<=ooo[x];i++){
			pq.push({ttt[x][i].first,ttt[x][i].second});
		}
		while(!pq.empty()){
			node p=pq.top();
			pq.pop();
			if(vis[p.v]){
				continue;
			}
			vis[p.v]=1;
			for(node j:g[p.v]){
				if(p.w+j.w<dis[j.v]){
					pq.push({j.v,p.w+j.w});
				}
			}
			dis[p.v]=min(p.w,dis[p.v]);
		}
		for(int i=1;i<=ooo[y];++i){
			ans=min(ans,w[x]+w[y]+ttt[y][i].second+dis[ttt[y][i].first]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

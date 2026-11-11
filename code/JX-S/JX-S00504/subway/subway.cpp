//subway
#include<bits/stdc++.h>
using namespace std;
#define emdl '\n'
typedef long long ll;
const int MAXN=500+5;
const int MAXM=5e5+5;
const int MAXQ=1e5+5;

int c,n,m,d,q;
int w[MAXM];
int k[MAXN],a[MAXN][MAXM],t[MAXN][MAXM];
int x[MAXQ],y[MAXQ];

void solve1(){
	vector<pair<int,int>> g[n*m+5];//[v,w]
	for(int i=1;i<=n;i++){
		for(int j=1;j+1<=k[i];j++){
			g[(i-1)*m+a[i][j]].push_back({(i-1)*m+a[i][j+1],0});
			g[(i-1)*m+a[i][j+1]].push_back({(i-1)*m+a[i][j],0});
		}
	}
	vector<int> sum[m+5];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			sum[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j:sum[i]){
			for(int l:sum[i]){
				if(j>=l) continue;
				else{
					g[(j-1)*m+i].push_back({(l-1)*m+i,t[j][i]+t[l][i]});
					g[(l-1)*m+i].push_back({(j-1)*m+i,t[j][i]+t[l][i]});
				}
			}
		}
	}
	
	for(int iii=1;iii<=q;iii++){
		int ans=0x3f3f3f3f;
		for(int i:sum[x[iii]]){
			int new_ans=0x3f3f3f3f;
			for(int j:sum[y[iii]]){
				int start=(i-1)*m+x[iii];
				int end=(j-1)*m+y[iii];
				int dis[n*m+5];
				memset(dis,0x3f,sizeof(dis));
				int vis[n*m+5];
				memset(vis,0,sizeof(vis));
				
				priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;//[cost,u]
				while(!q.empty()) q.pop();
				q.push({0,start});
				dis[start]=0;
				while(!q.empty()){
					auto fr=q.top();
					q.pop();
					int u=fr.second;
					vis[u]=1;
					
					if(u==end){
						new_ans=min(new_ans,dis[end]);
						break;
					}
					
					for(auto nxt:g[u]){
						int v=nxt.first;
						int ww=nxt.second;
						if(vis[v]) continue;
						if(dis[u]+ww<dis[v]){
							dis[v]=dis[u]+ww;
							q.push({dis[v],v});
						}
					}
				}
				
				new_ans+=t[i][x[iii]];
				new_ans+=t[j][y[iii]];
			}
			ans=min(ans,new_ans);
		}
		
		ans+=w[x[iii]];
		ans+=w[y[iii]];
		cout<<ans<<emdl;
	}
	
	return;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	
	solve1();
	
	return 0;
}

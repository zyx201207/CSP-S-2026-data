#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,INF=1e15;
struct node{
	int v;
	int w;
	bool operator<(const node&o)const{
		return w>o.w;
	}
};
int C,n,m,d,q,w[N],bian;
vector<node>G[N];
void case11(){
	for(int i=1;i<=n;i++){
		int k,a,t,lastm=-1;
		cin>>k;
		while(k--){
			cin>>a>>t;
			m++;
			G[a].push_back({m,t});
			G[m].push_back({a,t});
			if(lastm!=-1){
				G[m].push_back({lastm,0});
				G[lastm].push_back({m,0});
			}
			lastm=m;
		}
	}
	vector<vector<int>>dis(m+3,vector<int>(m+3,INF));
	while(q--){
		int x,y;
		cin>>x>>y;
		if(dis[x][x]!=0){
			priority_queue<node>q;
			q.push({x,0});
			dis[x][x]=0;
			while(!q.empty()){
				int u=q.top().v,ddis=q.top().w;
				q.pop();
				if(ddis!=dis[x][u]){
					continue;
				}
				for(const auto&i:G[u]){
					int v=i.v,w=i.w;
					if(dis[x][u]+w<dis[x][v]){
						dis[x][v]=dis[x][u]+w;
						q.push({v,dis[x][v]});
					}
				}
			}
		}
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
}
void case19(){
	int T;
	for(int i=1;i<=n;i++){
		int k,a,t,lastm=-1;
		cin>>k;
		while(k--){
			cin>>a>>T;
			m++;
			G[a].push_back({m,1});
			G[m].push_back({a,1});
			if(lastm!=-1){
				G[m].push_back({lastm,0});
				G[lastm].push_back({m,0});
			}
			lastm=m;
		}
	}
	vector<vector<int>>dis(m+3,vector<int>(m+3,INF));
	while(q--){
		int x,y;
		cin>>x>>y;
		if(dis[x][x]!=0){
			deque<int>q;
			q.push_front(x);
			vector<bool>vis(m+3,false);
			dis[x][x]=0;
			while(!q.empty()){
				int u=q.front();
				q.pop_front();
				if(vis[u]){
					continue;
				}
				vis[u]=true;
				for(const auto&i:G[u]){
					int v=i.v,w=i.w;
					if(dis[x][u]+w<dis[x][v]){
						dis[x][v]=dis[x][u]+w;
						if(w==0){
							q.push_front(v);
						}
						else{
							q.push_back(v);
						}
					}
				}
			}
		}
		cout<<dis[x][y]*T+w[x]+w[y]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(C<=11){
		case11();
		return 0;
	}
	if(C<=19){
		case19();
		return 0;
	}
	return 0;
}
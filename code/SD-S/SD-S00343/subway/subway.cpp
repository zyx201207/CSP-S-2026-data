#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+5,M=505;
vector<PII> g[N];
int k[M],a[M][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		g[i].push_back({i+n,w});
		g[i+n].push_back({i,w});
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		priority_queue<PII> q;
		q.push({0,x});
		vector<bool> vis;
		vector<int> dis;
		for(int i=1;i<=n;i++){
			dis[i]=0x3f3f3f;
		}
		while(!q.empty()){
			int t=q.top().first,id=q.top().second;
			q.pop();
			if(vis[t]) continue;
			vis[t]=true;
			for(auto tt:g[t]){
				int nw=tt.first,id1=tt.second;
				q.pop();
				if(vis[nw]) continue;
				vis[nw]=true;
				if(dis[id]>dis[id1]+nw){
					dis[id]=dis[id1]+nw;
					q.push({dis[id],id1});
				}
			}
		}
		cout<<dis[y]<<'\n';
	}
	return 0;
}

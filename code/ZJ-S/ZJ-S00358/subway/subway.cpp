#include<iostream>
#include<vector>
#include<queue>
#define PII pair<int,int>
#define int long long
#define INF 1e18
using namespace std;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int>w(m+1,0);
	vector<vector<PII>>sw(m+1);
	vector<vector<PII>>e(n+m+1);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int a,t;
			cin>>a>>t;
			sw[a].push_back({i,t});
			e[a].push_back({m+i,t});
			e[m+i].push_back({a,t});
		}
	}
	vector<vector<int>>dist(n+1,vector<int>(n+1,INF));
	for(int i=m+1;i<=m+n;i++){
		priority_queue<PII,vector<PII>,greater<PII>>pq;
		vector<int>tmpd(n+m+1,INF);
		vector<bool>vis(n+m+1,false);
		tmpd[i]=0;
		pq.push({0,i});
		while(!pq.empty()){
			PII tmp=pq.top();
			pq.pop();
			int u=tmp.second;
			int d=tmp.first;
			for(auto j:e[u]){
				int v=j.first;
				int w=j.second;
				if(tmpd[v]>d+w){
					tmpd[v]=d+w;
					pq.push({tmpd[v],v});
				}
			}
		}
		for(int j=1;j<=n;j++){
			dist[i-m][j]=tmpd[j+m];
		}
	}
	while(q--){
		int S,E;
		cin>>S>>E;
		int ans=INF;
		for(auto i:sw[S]){
			for(auto j:sw[E]){
				ans=min(ans,dist[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+w[S]+w[E]<<endl;
	}
}

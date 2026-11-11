#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bool first;
const int N=20011;
int c,t;
int n,d;
int x[N];
int vis[N];
int dis[N];
void dij(int s,vector<pii>e[]) {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	pq.push({0,s});
	dis[s]=0;
	bool mark[N]= {};
	while(pq.size()!=0) {
		int w=pq.top().second;
		pq.pop();
		if(mark[w])continue;
		mark[w]=true;
		//cout<<endl;
		/*for(int i=1;i<=n;i++){
			cout<<dis[i]<<" ";
		}*/
		//cout<<endl;
		for(int i=0; i<e[w].size(); i++) {
			int v=e[w][i].first,u=e[w][i].second;
			//cout<<dis[w]+v<<" ";
			if(dis[u]>dis[w]+v) {
				vis[u]=1;
				dis[u]=dis[w]+v;
				pq.push({dis[u],u});
			} else if(dis[u]==dis[w]+v) {
				vis[u]++;
				pq.push({dis[u],u});
			}
		}
	}
}

bool second;
int main() {
//	cerr<<(&second-&first)/1024/1024;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		vector<pii>e[N];
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(x[j]-x[i]>d)break;
				e[i].push_back({1,j});
			}
		}

		int sum=0;
		for(int i=1; i<=n; i++) {
			dij(i,e);
			for(int j=1;j<=n;j++){
				if(vis[j]==2)sum++;
			}
		}
		cout<<sum<<endl;
	}

	return 0;
}

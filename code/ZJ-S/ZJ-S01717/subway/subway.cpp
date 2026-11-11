#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bool first;
const int N=600011;
int c,n,m,d,q;
vector<pii>e[N];
map<pii,int>mp;
int dis[N];
int vis[N];
void dij(int s,bool mark[]){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	pq.push({0,s});
	dis[s]=0;
	while(pq.size()!=0){
		int w=pq.top().second;
		pq.pop();
		if(mark[w])continue;
		mark[w]=true;
		for(int i=0;i<e[w].size();i++){
			int v=e[w][i].first,u=e[w][i].second;
			if(dis[u]>dis[w]+v+mp[{w,w}]){
				dis[u]=dis[w]+v+mp[{w,w}];
				pq.push({dis[u],u});
			}
		}
	}
}
bool second;
int main() {
	//cerr<<(&second-&first)/1024/1024;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>vis[i];
	}
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			int ai,ti;
			cin>>ai>>ti;
			mp[{i,ai}]=ti;
			mp[{ai,i}]=ti;
			e[i].push_back({ti,ai});
			e[ai].push_back({ti,i});
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		bool mark[N]={};
		dij(x,mark);
		cout<<vis[x]+vis[y]+dis[y]<<endl;
	}
	return 0;
}

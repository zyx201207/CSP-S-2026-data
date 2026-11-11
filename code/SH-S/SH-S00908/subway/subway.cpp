#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN=505,MAXM=5e5+5,MAXNM=500500;
typedef pair<int,int> pii;
int c,n,m,d,q;
long long g[MAXM];
vector<pii> mp[MAXNM];

const int INF=0x3f3f3f3f;
int dis[MAXNM];
int vis[MAXNM];
vector<pii> qry[MAXM];
priority_queue<pii,vector<pii>,greater<pii> > pnt;
void solve(int x){
	for(int i=1;i<=n+m;i++){
		vis[i]=0;
		dis[i]=INF;
	}
	dis[x]=0;
	priority_queue<pii,vector<pii>,greater<pii> > que;
	que.push({0,x});
	while(!que.empty()){
		pii t=que.top();que.pop();
		int d=t.first,u=t.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:mp[u]){
			int v=i.first,w=i.second;
			if(d+w<dis[v]){
				dis[v]=d+w;
				que.push({d+w,v});
			}
		}
	}
	/*
	for(int i=1;i<=n+m;i++){
		cout << dis[i] << ' ';
	}
	*/
	for(auto i:qry[x]){
		int y=i.first;
		pnt.push({i.second,g[x]+g[y]+dis[y]});
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> g[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin >> v >> w;
			mp[i+m].push_back({v,w});
			mp[v].push_back({i+m,w});
		}
	}
	/*
	for(int i=1;i<=m;i++){
		cout << i << ":\n"; 
		for(auto j:mp[i]){
			cout << j.first << ' ' << j.second << endl;
		}
	}
	for(int i=m+1;i<=n+m;i++){
		cout << i << ":\n"; 
		for(auto j:mp[i]){
			cout << j.first << ' ' << j.second << endl;
		}
	}
	*/
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		qry[x].push_back({y,i});
	}
	for(int i=1;i<=m;i++){
		if(qry[i].size()){
			solve(i);
		}
	}
	while(!pnt.empty()){
		cout << pnt.top().second << endl;
		pnt.pop();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

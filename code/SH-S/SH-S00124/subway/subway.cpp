#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
const long long mx=1e18;
struct edge{
	long long v,w;
};
struct node{
	long long u,d;
	bool operator<(const node &a)const{
		return d>a.d;
	}
};
long long n,m,d,q,k,w[500050],dis[500550];
vector<edge>mp[500550];
int c;
void dijkstra(int s){
	for (int i=1;i<=n+m;i++){
		dis[i]=mx;
	}
	dis[s]=0;
	priority_queue<node>q;
	q.push({s,0});
	while (!q.empty()){
		node d=q.top();
		q.pop();
		if (dis[d.u]<d.d)continue;
		for (int i=0;i<mp[d.u].size();i++){
			edge v=mp[d.u][i];
			if (dis[d.u]+v.w<dis[v.v]){
				dis[v.v]=dis[d.u]+v.w;
				q.push({v.v,dis[v.v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			long long v,t;
			cin>>v>>t;
			mp[m+i].push_back({v,t});
			mp[v].push_back({m+i,t});
		}
	}
	for (int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		dijkstra(s);
		cout<<w[s]+w[t]+dis[t]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

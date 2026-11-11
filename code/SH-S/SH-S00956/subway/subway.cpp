#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
priority_queue<pair<int,int>,vector < pair < int,int > > ,greater < pair < int,int > > >q;
int dis[N],c,n,m,d,qq,w[N];
bool vis[N];
vector<pair<int,int>>g[N * 2];
void djk(int s){
	for(int i = 1; i <= 2 * m; i ++)
		dis[i] = 2e9 + 10;
	for(int i = 1; i <= 2 * m; i ++)
		vis[i] = false;
	dis[s] = 0;
	q.push({dis[s],s});
	while(!q.empty()){
		int f = q.top().second;
		q.pop();
		if(vis[f])
			continue;
		vis[f] = true;
		for(int i = 0; i < g[f].size(); i ++){
			int ff = g[f][i].first,l = g[f][i].second;
			if(dis[f] + l < dis[ff]){
				dis[ff] = dis[f] + l;
				q.push({dis[ff],ff});}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	if(7 <= c and c <= 11){
	for(int i = 1; i <= m; i ++)
		cin>>w[i];
	for(int i = 1; i <= m; i ++){
		g[m].push_back({i + m,w[i]});
		g[i + m].push_back({m,w[i]});}
	for(int i = 1; i <= n; i ++){
		int k,aa,tt,a,t;
		cin>>k;
		if(k == 1)
			continue;
		cin>>a>>t>>aa>>tt;
		g[a].push_back({aa,t + tt});
		g[aa].push_back({a,t + tt});}
	for(int i = 1; i <= qq; i ++){
		int a,b;
		cin>>a>>b;
		djk(a);
		cout<<dis[b]<<endl;
	}}
	return 0;
}

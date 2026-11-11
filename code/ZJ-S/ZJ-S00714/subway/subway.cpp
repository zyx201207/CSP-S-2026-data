#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[500010];
int c,n,m,d,q;
vector<pair<int,int> > s[510],t[500010];
long long bfs(int start,int end){
	vector<ll> dis(m+1,LONG_MAX),dis2(n+1,LONG_MAX);
	dis[start]=0;
	queue<pair<int,bool> > q;
	q.push({start,0});
	while(!q.empty()){
		pair<int,bool> f=q.front();q.pop();
		int u=f.first;
		bool flag=f.second;
		if(flag){
			for(int i=0;i<s[u].size();i++){
				int v=s[u][i].first,w=s[u][i].second;
				if(dis[v]>dis2[u]+w){
					dis[v]=dis2[u]+w;
					q.push({v,0});
				}
			}
		}else{
			for(int i=0;i<t[u].size();i++){
				int v=t[u][i].first,w=t[u][i].second;
				if(dis2[v]>dis[u]+w){
					dis2[v]=dis[u]+w;
					q.push({v,1});
				}
			}
		}
	}
//	for(int i=1;i<=m;i++) cout<<dis[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n;i++) cout<<dis2[i]<<" ";
//	cout<<endl;
	return dis[end];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,time;
			cin>>a>>time;
			s[i].push_back({a,time});
			t[a].push_back({i,time});
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<bfs(u,v)+w[u]+w[v]<<endl;
	}
	return 0;
}

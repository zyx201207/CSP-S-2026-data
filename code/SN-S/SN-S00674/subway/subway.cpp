#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace Vesperon{
	const int N=1e6+7;
	ll dist[N],c,n,m,d,q,w[N],k[N],a[505][505],r,x,y,t[505][505];
	vector<vector<pair<int,int>> > g(N);
	void dij(int s){
		dist[s]=0;
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > qp;
		qp.push({s,0});
		while(!qp.empty()){
			int u=qp.top().first;
			int v=qp.top().second;
			qp.pop();
			cout<<u<<" "<<v<<endl;
			for(auto &e : g[u]){
				int d=e.first;
				int w=e.second;
				if(d!=dist[u]) continue;
				if(dist[v]>d+w){
					dist[v]=d+w;
					cout<<dist[v]<<endl;
					qp.push({dist[v],v});
				}
			}
		}
	}
	void work(){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>w[i];
			g[u]
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
				int uu=a[i][j-1];
				g[uu].push_back({a[i][j],t[i][j]});
			}
			dij(a[1][1]);
		}
		for(auto& e:g[1]){
			int v=e.first;
			int w=e.second;
			cout<<v<<" "<<w<<endl;
		}
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			cout<<dist[y]-dist[x];
		}
		
	}
	//做不出来……
	//dij肯定写错了，但是不知道错在哪里。
	//18:16了。
	//我常常追忆过去。
	//Wing it now!Cast aside the unchanging score
	//Win it now!We aren't bolted parts anymore
	//Swing now!Be the sharp no one can ignore
	//Ready to surprise them all,freely aloud!
	//Qaaxaap,Pulsar,Revalitize
	//114514
	//Close windows,open the door.
	//Don't panic.
	//My whole existence is hopeless.
	//Am I supposed to do something?
	//Just die on the dancefloor.
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	return Vesperon::work() ,0;
}

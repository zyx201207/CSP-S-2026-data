#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >g[500505];
struct node{
	int x;
	int s;
};
int c,n,m,d,q;
int w[500005];
int dust[500505],vis[500505];
int main(){
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=m+1;i<=m+n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({i,t});
			g[i].push_back({a,t});
		}
	}
	while(q--){
		priority_queue<pair<int,pair<int,int> > >qu;
		int sx,sy;
		cin>>sx>>sy;
		qu.push({0,{sx,-1}});
		for(int i=1;i<=m+n;i++)dust[i]=INT_MAX;
		dust[sx]=0;
		while(!qu.empty()){
			pair<int,pair<int,int> > now=qu.top();
			int u=qu.top().second.first;
			int fa=qu.top().second.second;
			int s=-qu.top().first;
			qu.pop();
			if(s>dust[u])break;
			for(int i=0;i<g[u].size();i++){
				int v=g[u][i].first;
				int len=g[u][i].second;
				if(v!=fa){
	//					cout<<v<<" "<<u<<" "<<fa<<"\n";
					if(dust[v]>dust[u]+len){
						dust[v]=dust[u]+len;
						qu.push({-dust[v],{v,u}});
	//						cout<<u<<"->"<<v<<"\n";
	//						cout<<dust[u]<<"+"<<len<<"="<<dust[v]<<"\n";
					}
				}
			}
		}
		cout<<dust[sy]+w[sx]+w[sy]<<"\n";
	}
	return 0;
}/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

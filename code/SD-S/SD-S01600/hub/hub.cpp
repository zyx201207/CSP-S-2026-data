#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int c,t,n,k;
struct edge{
	int t;
	edge(int to):t(to){}
};
vector<edge> g[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(edge(v));
			g[v].push_back(edge(u));
		}
		cout<<rand()%INT_MAX<<"\n";
	}
	return 0;
} 

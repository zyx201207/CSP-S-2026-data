#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
struct z{
	int a,t;
}h[500005];
vector<int> g[500005];
int p[500005];
void dfs(int l,int r){
	for(int i=0;i<g[l].size();i++){
		dfs(g[l][i],r);
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>h[j].a>>h[j].t;
		}
		for(int j=2;j<=k;j++){
			g[h[j-1].a].push_back(h[j].a);
			g[h[j].a].push_back(h[j-1].a);
		}
	}
	int s1=0;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dfs(x,y);
		cout<<p[x][y];
	}
} 

#include<bits/stdc++.h> 
using namespace std;
struct Edge{
	int line,from;
};
int c,n,m,d,q,w[5001];
int t[501][5001];
long long l[501];
bool vis[501];
vector<Edge> subway[5001];
inline void dfs(int end,int sta,long long time){
	if(sta==end){
		l[end]=min(l[end],time);
		return;
	}
	l[sta]=min(l[sta],time);
	time=min(time,l[sta]);
	for(auto x:subway[sta])
		if(!vis[x.from]){
			vis[x.from]=1;
			dfs(end,x.from,time+t[x.line][sta]+t[x.line][x.from]);
			vis[x.from]=0;
		}
}
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int pt=0;
		for(int j=1;j<=k;j++){
			int a,f;
			cin>>a>>f;
			t[i][a]=f;
			subway[a][i].from=pt;
			subway[a][i].line=i;
			pt=a;
		}
	}
	while(q--){
		memset(l,127,sizeof(l));
		memset(vis,0,sizeof(vis));
		int x,y;
		cin>>x>>y;
		dfs(x,y,0);
		cout<<w[x]+w[y]+l[x]<<' ';
	}
}

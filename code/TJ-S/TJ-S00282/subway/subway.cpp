#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
const ll P=1e18;
int c,n,m,d,qq,k[N];
ll w[N],b[501][1001];
bool vis[1001][1001],fl[1001][1001];
vector<int>mm[N];
struct node{
	int x;
	ll t;
};
struct edge{
	int x,w,lst;
	bool operator>(const edge& o)const{
		return w<o.w;
	}
};
struct pp{
	ll v;
	int l;
}dp[1000][1001];
vector<node>g[600];
priority_queue<edge,vector<edge>,greater<edge> >q;
void dij(int x,int y){
	q.push({x,w[x],0});
	while(!q.empty()){
		edge t=q.top();
		q.pop();
		if(vis[x][t.x]) continue;
		vis[x][t.x]=true;
		for(int l:mm[t.x]){
			if(l==t.l) continue;
			for(node v:g[l]){
				if(vis[x][v.x]==false&&x!=v.x&&dp[x][v.x].v>t.t+b[l][t.x]+b[l][v.x]){
					dp[x][v.x]={t.t+b[l][t.x]+b[l][v.x],l};
					q.push({v.x,t.t+b[l][t.x]+b[l][v.x],l});
				}
			}
		}
		
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,t;j<=k[i];j++){
			cin>>x>>t;
			g[i].push_back({x,t});
			b[i][x]=t;
			mm[x].push_back(i);
		}
	} 
	int x,y;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=P;
		}dp[i][i]=0;
	}
	while(qq--){
		cin>>x>>y;
		if(!dp[x][y]) dij(x,y);
		cout<<dp[x][y].v-b[dp[x][y].l][y]+w[y]<<'\n';
	}
	return 0;
}


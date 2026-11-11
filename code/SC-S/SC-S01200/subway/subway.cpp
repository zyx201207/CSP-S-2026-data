#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5,inf=1e18+7;
int c,n,m,d,T,w[M];
int dis[505][505];
vector<int> ari[M];
vector<int> art[M];
int head[M],tot;
struct node{
	int cur,nxt,val;
}eg[M*4];
void add(int x,int y,int z){
	eg[++tot].cur=y;
	eg[tot].nxt=head[x];
	eg[tot].val=z;
	head[x]=tot;
}
priority_queue<pair<int,int> > q;
void dij(int s){
	for(int i=1;i<=n;i++) dis[s-m][i]=inf;
	dis[s-m][s-m]=0;q.push({0,s-m});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		for(int i=head[u+m];i;i=eg[i].nxt){
			int v=eg[i].cur;
			if(dis[s-m][v-m]>dis[s-m][u]+eg[i].val){
				dis[s-m][v-m]=dis[s-m][u]+eg[i].val;
				q.push({-dis[s-m][v-m],v-m});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			ari[a].push_back(m+i);art[a].push_back(t);
		}
	}
	for(int i=1;i<=m;i++){
		for(int x=0;x<ari[i].size();x++){
			for(int y=x+1;y<ari[i].size();y++){
				add(ari[i][x],ari[i][y],art[i][x]+art[i][y]);
				add(ari[i][y],ari[i][x],art[i][x]+art[i][y]);
				//cout<<ari[i][x]<<" "<<ari[i][y]<<"\n";
			}
		}
	}
	for(int i=m+1;i<=m+n;i++) dij(i);
	while(T--){
		int x,y,ans=inf;cin>>x>>y;
		for(int i=0;i<ari[x].size();i++){
			for(int j=0;j<ari[y].size();j++){
				//cout<<ari[x][i]<<" "<<ari[y][j]<<"\n";
				ans=min(ans,dis[ari[x][i]-m][ari[y][j]-m]+art[x][i]+art[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=525,M=5e5+25,inf=1e9;//1<=w[i],t[i][j]<=1e9&&1<=k[i],a[i][j]<=5e5&&1<=x[r],y[r]<=5e5(x[r]!=y[r])
struct node{
	int x,y,at,step;
	bool operator <(const node& X)const{
		return X.step>step;
	}
};
struct edge{
	int x,y,at;
};
int c,n,m,d,q,anser;
int w[M],k[N],a[N][N],t[N][N];
vector<edge>G[N];
int vis1[M],vis2[N];
void dijstra(int x,int y){
	priority_queue<node>q;
	for(int i=1;i<=n;i++){
		vis2[i]=inf;
	}
	for(int i=1;i<=m;i++){
		vis1[i]=inf;
	}
	for(int i=0;i<G[x].size();i++){
		q.push({G[x][i].x,G[x][i].y,x,w[x]+t[G[x][i].x][G[x][i].y]});
		vis2[x]=0;
		vis1[G[x][i].x]=0;
	}
	while(q.size()){
		node f=q.top();
		q.pop();
		if(f.at==y){
			anser=f.step+w[f.at]+t[f.x][f.y];
			return ;
		}
		if(vis2[a[f.x][f.y+1]]>f.step){
			vis2[a[f.x][f.y+1]]=f.step;
			q.push({f.x,f.y+1,a[f.x][f.y+1],f.step});
		}
		if(vis2[a[f.x][f.y-1]]>f.step){
			vis2[a[f.x][f.y-1]]=f.step;
			q.push({f.x,f.y-1,a[f.x][f.y-1],f.step});
		}
		for(int i=0;i<G[f.at].size();i++){
			int xx=G[f.at][i].x,yy=G[f.at][i].y,step=f.step+t[f.x][f.y]+t[xx][yy];
			if(vis2[a[xx][yy]]>=step||vis1[xx]>=step){
				vis2[a[xx][yy]]=min(vis2[a[xx][yy]],step);
				vis1[xx]=min(vis1[xx],step);
				q.push({xx,yy,a[xx][yy],step});
			}
		}
	}
	return;
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			G[a[i][j]].push_back({i,j,a[i][j]});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<endl;
			continue;
		}
		dijstra(x,y);
		cout<<anser<<endl;
	}
	return ;
}
signed main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

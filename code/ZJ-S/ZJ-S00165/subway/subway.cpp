#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int ttt=0;
int c,n,m,d,q,dist1[500005],x,y;
int k[505],a[505][505],t[505][505];
bool vis[500005];
int gs[500005];
struct node{
	int u,w;
	bool operator <(const node& __x) const
    { return w < __x.w; }
};
struct xx{
	int v,dis;
} g[500005][30];
int dis[2005][2005];
inline int dijs(int x,int y){
	if(dis[x][y]<1e9)return dis[x][y];
	priority_queue<node>q;
	q.push({x,0});
	while(!q.empty()){
		auto tt=q.top();
		q.pop();
		for(int i=1;i<=gs[tt.u];i++){
			if(tt.w+g[tt.u][i].dis<dis[x][g[tt.u][i].v]){
				dis[x][g[tt.u][i].v]=tt.w+g[tt.u][i].dis;
				q.push({g[tt.u][i].v,tt.w+g[tt.u][i].dis});
			}
		}
	}
	return dis[x][y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		cin>>dist1[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=d;j++)g[i][j].dis=0x3f3f3f3f;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				if(g[a[i][l]][++gs[a[i][l]]].dis>t[i][l]+t[i][j])
					g[a[i][l]][gs[a[i][l]]]={a[i][j],t[i][l]+t[i][j]};
				if(g[a[i][j]][++gs[a[i][j]]].dis>t[i][l]+t[i][j])
					g[a[i][j]][gs[a[i][j]]]={a[i][l],t[i][l]+t[i][j]};
			}
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<dijs(x,y)+dist1[x]+dist1[y]<<"\n";
	}
	return 0;
}
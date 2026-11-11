#include <bits/stdc++.h>
#define int long long
#define qjq nb666
using namespace std;
//t2
int f[505][505];//zhan jian juli
int dis[500005];
int c,n,m,d,q;
struct node{
	int x,y;
};
vector<node>v[500005];
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				//cout<<i<<" "<<j<<" "<<k<<"\n";
				f[j][k]=min(f[j][i]+f[i][k],f[j][k]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>dis[i];
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[i].size();k++){
				if(j==k)continue;
				f[v[i][j].x][v[i][k].x]=min(f[v[i][j].x][v[i][k].x],v[i][j].y+v[i][k].y);
			}
		}
	}
	floyd();
	while(q--){
		int x,y;cin>>x>>y;
		int res=2e17;
		for(auto xv:v[x]){
			for(auto yv:v[y]){
				//if(xv.x!=yv.x)continue;
				res=min(res,f[xv.x][yv.x]+xv.y+yv.y);
			}
		}
		cout<<res+dis[x]+dis[y]<<"\n";
	}
}
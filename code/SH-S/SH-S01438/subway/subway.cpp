#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,c,d,q,l,a,b,u,v;
ll w[500005],dis[505][505],res,x,y;
struct station{
	int v;
	ll w;
};
vector<station> g[500505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>l;
		for(int j=1;j<=l;j++){
			cin>>a>>b;
			g[a].push_back({i,b});
		}
	}
	memset(dis,0x3f,sizeof(dis));
//	cout<<"gen\n";
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto j1:g[i]){
			u=j1.v,x=j1.w;
			for(auto j2:g[i]){
				v=j2.v,y=j2.w;
				dis[u][v]=dis[v][u]=min(dis[u][v],x+y);
			}
		}
	}
//	cout<<"dis\n";
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	cout<<"floyd\n";
	while(q--){
		cin>>a>>b;
		res=dis[0][0];
		for(auto j1:g[a]){
			u=j1.v,x=j1.w;
			for(auto j2:g[b]){
				v=j2.v,y=j2.w;
				res=min(res,w[a]+w[b]+x+y+dis[u][v]);
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}

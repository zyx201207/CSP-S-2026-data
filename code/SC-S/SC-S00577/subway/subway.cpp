//O damn its crazy
//Im going to write a O(1e8) solution
//Can I AC? Here we go
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18;
const int N=5e5+5;
int n,m,q;
ll sw[N];
struct edge{
	int y;
	ll w;
};
vector<edge>st[N];
ll dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int gunmu;
	cin>>gunmu>>n>>m>>gunmu>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=inf;
		} 
	}
	for(int i=1;i<=m;i++){
		cin>>sw[i];
	}
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int x;
			ll w;
			cin>>x>>w;
			st[x].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto itx:st[i]){
			for(auto ity:st[i]){
				int x=itx.y;
				int y=ity.y;
				ll w=itx.w;
				ll z=ity.w;
				dis[x][y]=min(dis[x][y],w+z);
				dis[y][x]=dis[x][y];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ll ans=inf;
		int x,y;
		cin>>x>>y;
		for(auto itx:st[x]){
			for(auto ity:st[y]){
				ll tmp=dis[itx.y][ity.y]+itx.w+ity.w+sw[x]+sw[y];
				ans=min(ans,tmp);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//OMG I accept all the big yangli
//I begin to feel nervous
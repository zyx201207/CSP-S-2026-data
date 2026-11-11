#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int c,n,m,d,q;
ll w[500100],k[550],a[550][550],dis[550][550];
struct sta{
	ll w,t;
};
vector<sta> t[500100];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i]; 
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			ll aaa;
			cin>>aaa;
			t[a[i][j]].push_back({i,aaa});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(int j=0;j<t[i].size();j++){
			for(int k=j+1;k<t[i].size();k++){
				dis[t[i][k].w][t[i][j].w]=dis[t[i][j].w][t[i][k].w]=t[i][j].t+t[i][k].t;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=dis[k][j]=min(dis[j][k],dis[i][j]+dis[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		ll ans=1e18;
		cin>>x>>y;
		for(int j=0;j<t[x].size();j++){
			for(int k=0;k<t[y].size();k++){
				ans=min(ans,dis[t[x][j].w][t[y][k].w]+w[x]+w[y]+t[x][j].t+t[y][k].t);
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
}


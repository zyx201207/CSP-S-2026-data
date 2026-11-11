#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,k[505];
ll w[500005];
struct node{
	int lne;
	ll tim;
};
vector<node> hc[500005];
vector<pair<int,ll> > dtx[505];
ll dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,a,t;j<=k[i];j++){
			cin>>a>>t;
			hc[a].push_back({i,t});
			dtx[i].push_back({a,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			dis[i][j]=LONG_LONG_MAX;
		}
	for(int i=1;i<=n;i++){
		for(pair<int,int> ljz:dtx[i]){
			for(node ljzz:hc[ljz.first]){
				dis[i][ljzz.lne]=dis[ljzz.lne][i]=min(dis[i][ljzz.lne],ljz.second+ljzz.tim);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][k]!=LONG_LONG_MAX&&dis[k][j]!=LONG_LONG_MAX)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		ll ans=LONG_LONG_MAX;
		for(node u:hc[x]){
			for(node v:hc[y]){
				if(dis[u.lne][v.lne]!=LONG_LONG_MAX) ans=min(ans,w[x]+w[y]+u.tim+v.tim+dis[u.lne][v.lne]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[505],c,n,m,d,q,dis[505][505];
vector<pair<int,int> >ve[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t,a;
			cin>>a>>t;
			ve[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<ve[i].size();j++){
			for(int k=0;k<ve[i].size();k++){
				if(j==k){
					continue;
				}
				ll qa=ve[i][j].first,qb=ve[i][k].first,kk=ve[i][j].second+ve[i][k].second;
				dis[qa][qb]=min(dis[qa][qb],kk);
				dis[qb][qa]=min(dis[qb][qa],kk);
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
	for(int o=1;o<=q;o++){
		int x,y;
		cin>>x>>y;
		ll pp=w[x]+w[y],ppp=1e18;
		for(ll i=0;i<ve[x].size();i++){
			for(ll j=0;j<ve[y].size();j++){
				ll qa=ve[x][i].first,qb=ve[y][j].first,kk=ve[x][i].second+ve[y][j].second;
				ppp=min(ppp,kk+dis[qa][qb]);
			}
		}
		pp+=ppp;
		cout<<pp<<"\n";
	}
	return 0;
}
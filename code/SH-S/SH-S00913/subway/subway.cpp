#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
long long c,n,m,d,q,dis[510][510],w[500010],mp[500010][25],sz[500010],id[500010][25];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){cin>>w[i];}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x;j<=k;j++){
			cin>>x;
			id[x][++sz[x]]=i;
			cin>>mp[x][sz[x]];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dis[i][j]=dis[j][i]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=sz[i];j++){
			for(int k=1;k<=sz[i];k++){
				if(j==k){continue;}
				dis[id[i][j]][id[i][k]]=dis[id[i][k]][id[i][j]]=min(dis[id[i][j]][id[i][k]],mp[i][j]+mp[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k){continue;}
			for(int j=i+1;j<=n;j++){
				if(k==j){continue;}
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
	for(int x,y,i=1;i<=q;i++){
		cin>>x>>y;
		long long ans=inf;
		for(int j=1;j<=sz[x];j++){
			for(int k=1;k<=sz[y];k++){
				ans=min(ans,dis[id[x][j]][id[y][k]]+w[x]+w[y]+mp[x][j]+mp[y][k]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

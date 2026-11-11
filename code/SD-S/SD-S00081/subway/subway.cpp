#include<bits/stdc++.h>
using namespace std;
const int maxn=500,maxm=1e6;
long long r[maxn+5][maxn+5],w[maxm+5],dis[maxn+5][maxn+5];
vector<pair<long long,long long> > g[maxm+5];
long long m,n,c,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			long long a,t;
			cin>>a>>t;
			g[a].push_back(make_pair(i+m,t));
			g[i+m].push_back(make_pair(a,t));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) r[i][i]=0;
			else r[i][j]=1e15;
		}
	}
	//cout<<'*';
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			long long u=g[i][j].first,t1=g[i][j].second;
			for(int k=0;k<g[i].size();k++){
				int v=g[i][k].first,t2=g[i][k].second;
				if(u==v) continue;
				r[u-m][v-m]=min(r[u-m][v-m],t1+t2);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)dis[i][j]=1e15;
		}
	}
	for(int k=1;k<=n;k++){
		for(int u=1;u<=n;u++){
			if(k!=u){
				dis[k][u]=min(r[u][k],dis[u][k]);
			}
			dis[u][k]=dis[k][u];
		}
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				if(u==v) continue;
				dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
				dis[v][u]=dis[u][v];
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		long long ans=1e15;
		for(int i=0;i<g[a].size();i++){
			long long u=g[a][i].first,t1=g[a][i].second;
			for(int j=0;j<g[b].size();j++){
				long long v=g[b][j].first,t2=g[b][j].second;
				ans=min(ans,dis[u-m][v-m]+t1+t2);
			}
		}
		cout<<ans+w[a]+w[b]<<endl;
	}
	return 0;
}

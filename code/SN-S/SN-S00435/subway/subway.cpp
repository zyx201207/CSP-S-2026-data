#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
vector<pair<int,int> > e[505]; //a t
vector<pair<int,int> > xl[500005];   //每站经过的线路 
pair<int,int> huan[505][505];
int dis[505][505];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			e[i].push_back({a,t});
			xl[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=-1;
		dis[i][i]=0;
	}
	for(int k=1;k<=m;k++){
		for(int i=0;i<xl[k].size();i++){
			int u=xl[k][i].first;
			int uw=xl[k][i].second;
			for(int j=i+1;j<xl[k].size();j++){
				int v=xl[k][j].first;
				int vw=xl[k][j].second;
				if(dis[u][v]==-1){
					dis[u][v]=dis[v][u]=uw+vw;
					huan[u][v]=huan[v][u]={k,k};
				}
				else if(dis[u][v]>uw+vw){
					dis[u][v]=dis[v][u]=uw+vw;
					huan[u][v]=huan[v][u]={k,k};
				}
			} 
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i) continue;
			for(int j=1;j<=n;j++){
				if(k==j||dis[i][k]==-1||dis[k][j]==-1) continue;
				if(dis[i][j]==-1){
					dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
					huan[i][j]={huan[i][k].first,huan[k][j].second};
					huan[j][i]={huan[k][j].second,huan[i][k].first};
				}
				else if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
					huan[i][j]={huan[i][k].first,huan[k][j].second};
					huan[j][i]={huan[k][j].second,huan[i][k].first};
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<i<<" "<<j<<" "<<dis[i][j]<<" ";
			cout<<huan[i][j].first<<" "<<huan[i][j].second<<'\n';
		}
	}*/
	while(q--){
		int l,r;
		cin>>l>>r;
		int ans=w[l]+w[r];
		int res=LLONG_MAX;
		for(int i=0;i<xl[l].size();i++){
			int u=xl[l][i].first;
			int uw=xl[l][i].second;
			for(int j=0;j<xl[r].size();j++){
				int v=xl[r][j].first;
				int vw=xl[r][j].second;
				if(u==v){
					res=min(res,uw+vw);
					continue;
				}
				int kk=dis[u][v]+uw+vw;
				if(l==huan[u][v].first) kk-=uw;
				if(r==huan[u][v].second) kk-=vw;
				//cout<<u<<" "<<v<<" "<<kk<<'\n';
				res=min(res,kk);
			}
		}
		cout<<ans+res<<'\n';
	}
	return 0;
}

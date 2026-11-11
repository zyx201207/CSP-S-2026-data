#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long> >xl[600000];
int r[600000];
long long g[600][600],dis[600][600];
bool b[600][600];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,n,m,d,q,i,j,l;//  N地铁线路数  M地铁站数
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++) cin>>r[i];
	for(i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int v,w;
			cin>>v>>w;
			xl[v].push_back(make_pair(i,w));
		}
	}
	memset(g,0x3f,sizeof(g));
	for(i=1;i<=n;i++) g[i][i]=0;
	for(i=1;i<=m;i++){
		int k=xl[i].size();
		for(j=0;j<k;j++){
			for(l=j+1;l<k;l++){
				g[xl[i][j].first][xl[i][l].first]=g[xl[i][l].first][xl[i][j].first]=min(g[xl[i][l].first][xl[i][j].first],xl[i][j].second+xl[i][l].second);
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(i=1;i<=n;i++) dis[i][i]=0;
	for(l=1;l<=n;l++){
		priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;q.push(make_pair(0,l));
		while(!q.empty()){
			int u=q.top().second;q.pop();
			if(b[l][u]) continue;b[l][u]=1;
			for(i=1;i<=n;i++){
				long long v=i,w=g[u][i];
				if(!b[l][v]&&dis[l][u]+w<dis[l][v]) dis[l][v]=dis[l][u]+w,q.push(make_pair(dis[l][u]+w,v));
			}
		}
	}
	while(q--){
		int s,t;
		long long ans=LLONG_MAX;
		cin>>s>>t;
		for(i=xl[s].size()-1;i>=0;i--){
			for(j=xl[t].size()-1;j>=0;j--){
				ans=min(ans,xl[s][i].second+dis[xl[s][i].first][xl[t][j].first]+xl[t][j].second);
			}
		}
		cout<<ans+r[s]+r[t]<<'\n';
	}
	return 0;
}

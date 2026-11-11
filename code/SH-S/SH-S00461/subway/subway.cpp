#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long dist[505][505],ans;
vector<pair<int,long long>>tu[505];//各线路到达别的线路所需时间 
struct Sub{
	int w;
	vector<pair<int,int>>t;//线路+时间 
}sub[500002];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;//测试点编号 地铁线路数 地铁站数 每个地铁站最多几条线经过 出行计划数
	for(int i=1;i<=m;i++)cin>>sub[i].w;//每个地铁站从地铁口走到站厅的时间
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1,f=0;j<=k;j++){
			int a,tt;cin>>a>>tt; 
			sub[a].t.push_back({i,tt});
		}
		for(int j=1;j<=n;j++)dist[i][j]=1e18;
		dist[i][i]=0;
	} 
	for(int i=1;i<=m;i++){
		for(int j=0;j<sub[i].t.size();j++){
			int x=sub[i].t[j].first,s=sub[i].t[j].second;
			for(int k=0;k<sub[i].t.size();k++){
				int y=sub[i].t[k].first,tt=sub[i].t[k].second;
				if(x!=y){
					dist[x][y]=min(dist[x][y],1ll*s+tt);
					dist[y][x]=min(dist[y][x],1ll*s+tt);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<sub[x].t.size();i++){
			int from=sub[x].t[i].first,s=sub[x].t[i].second;
			for(int j=0;j<sub[y].t.size();j++){
				int to=sub[y].t[j].first,tt=sub[y].t[j].second;
				ans=min(ans,dist[from][to]+s+tt);
			}
		}
		ans+=sub[x].w+sub[y].w;
		cout<<ans<<'\n';
	} 
	return 0;
}

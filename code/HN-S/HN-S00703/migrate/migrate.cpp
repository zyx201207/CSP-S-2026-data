#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fir first
#define sec second
const int N=2e6+1145;
int n,d,x[N],cnt[505][505],dis[505][505],g[505][505];
//vector<int> g[5005];
//bool vis[505];
/*
void dijkstra(int s){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,s});
	for(int i=0;i<=n;i++)dis[s][i]=1e18,vis[i]=0;
	dis[s][s]=0;cnt[s][s]=1;
	while(q.size()){
		int u=q.top().sec;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:g[u]){
			if(dis[s][v]>dis[s][u]+1){
				cnt[s][u]=cnt[s][v];
				dis[s][v]=dis[s][u]+1;
				q.push({dis[s][v],v});
			}else if(dis[s][v]==dis[s][u]+1)cnt[s][u]+=cnt[s][u]*cnt[s][v];
		}
	}
}*/
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(g,0x3f,sizeof g);
		memset(cnt,0,sizeof cnt);
		
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if((x[j]-x[i])<=d){
					//g[i].push_back(j),g[j].push_back(i);
					g[i][j]=g[j][i]=cnt[i][j]=cnt[j][i]=1;
				}else break;
		for(int i=1;i<=n;i++)g[i][i]=0,cnt[i][i]=0;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(g[i][j]>g[i][k]+g[k][j])cnt[i][j]=cnt[i][k]*cnt[k][j];
					else if(g[i][j]==g[i][k]+g[k][j])cnt[i][j]+=cnt[i][k]*cnt[k][j];
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
				//
			}
		}
		
		//for(int i=1;i<=n;i++)dijkstra(i);
		
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if(cnt[i][j]==2)ans++;
		cout<<ans<<"\n";
		
		/*for(int i=1;i<=n;i++,cout<<"\n"){
			for(int j=1;j<=n;j++)cout<<cnt[i][j]<<" ";
		}
		
		cout<<"\n\n\n";*/
	}
	return 0;
}
//¹òÇó 6 ¹³ plz
//luogu 991587
//rp++ 

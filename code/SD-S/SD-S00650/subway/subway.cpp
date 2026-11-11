#include<bits/stdc++.h>
#define int long long
#define maxn 5005
#define maxd 25
#define maxm 505
using namespace std;
using pii=pair<int,int>;
int C,n,m,D,q;
int w[maxn];
vector<pii>g[maxn*maxd];
vector<int>a[maxm];
void add(int x,int y,int val){
	g[x].push_back({y,val});
	g[y].push_back({x,val});
}
int mp[maxn][maxd];//node i's j-th appearance's number
int cnt[maxn];//node i's appearances in the lines
pii hs[maxn*maxd];//the real node number of the vitual numbers
int nv[maxn][maxd];//node i's j-th appearance's val
int tot;
int dis[maxn][maxn];
int dij(int st){
	priority_queue< pii,vector<pii>,greater<pii> >q;
	q.push({0,st});
	dis[st][st]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
//		vis[u]=1;
		for(auto vv:g[u]){
			int v=vv.first,w=vv.second;
			if(dis[st][u]+w<dis[st][v]){
				dis[st][v]=dis[st][u]+w;
				q.push({dis[st][v],v});
			}
		}
	}
}
void init(){
	memset(dis,0x3f,sizeof(dis));
	int sum=0;
	for(int i=1;i<=tot;i++){
		dij(i);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>m>>n>>D>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,val;
			cin>>x>>val;
			cnt[x]++;
			mp[x][cnt[x]]=++tot;
			nv[x][cnt[x]]=val;
			a[i].push_back(tot);
			hs[tot]={x,cnt[x]};
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<a[i].size();j++){
			add(a[i][j],a[i][j-1],0);//subway edges cost nothing
		}
	}
	for(int s=1;s<=n;s++){
		for(int j=1;j<=cnt[s];j++){
			for(int k=j+1;k<=cnt[s];k++){
				int rj=mp[s][j],rk=mp[s][k];
				add(rj,rk,nv[s][j]+nv[s][k]);
			}
		}
	}
	init();
	int ans=LLONG_MAX;
	while(q--){
		ans=LLONG_MAX;
		int s,d;
		cin>>s>>d;
		for(int i=1;i<=cnt[s];i++){
			for(int j=1;j<=cnt[d];j++){
				ans=min(ans,dis[mp[s][i]][mp[d][j]]+nv[s][i]+nv[d][j]);
			}
		}
//		cout<<ans<<"-->";
		cout<<ans+w[s]+w[d]<<"\n";
	}
	return 0;
}

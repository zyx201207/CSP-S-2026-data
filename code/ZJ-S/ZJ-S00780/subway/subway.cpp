#include<bits/stdc++.h>
#define I_don_t_want_to_AFO int main()
#define I_want_to_study_OI_forever return 0;
using namespace std;
const int N=505,M=500005,D=25;
long long c,n,m,d,q;

long long w[500005];//mei ge zhan de chu zhan shi jian
struct node{
	long long v,w;
};

long long x,t;
long long k[505];//di i tiao xian lu suo lian jie de zhan shu
vector<node>e[500005];//mei ge zhan lian jie de xian lu

long long ew[505][505];
bool ewvis[505][505];
long long dis[505][505];
bool vis[505][505];
void dij(int s,int l){
	for(int i=1;i<=n;i++){
		dis[l][i]=1e18;
		vis[l][i]=0;
	}
	priority_queue<pair<long long,int> >pq;
	pq.push({0,s});
	dis[l][s]=0;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[l][u])continue;
		vis[l][u]=1;
		for(int i=1;i<=n;i++){
			if(ewvis[u][i]==0)continue;
			if(dis[l][u]+ew[u][i]<dis[l][i]){
				dis[l][i]=dis[l][u]+ew[u][i];
				pq.push({-dis[l][i],i});
			}
		}
	}
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}

	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long x,t;
			cin>>x>>t;
			e[x].push_back({i,t});
		}
	}
	//chu shi hua ji da zhi shi bian ju zhen
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)ew[i][j]=0;
			else ew[i][j]=1e18;
		}
	}
	// chu li shi bian
	for(int i=1;i<=m;i++){
		int len=e[i].size();
		for(int p=0;p<len;p++){
			for(int q=0;q<len;q++){
				ew[e[i][p].v][e[i][q].v]=ew[e[i][q].v][e[i][p].v]=min(e[i][p].w+e[i][q].w,ew[e[i][q].v][e[i][p].v]);
				ewvis[e[i][p].v][e[i][q].v]=1;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<ew[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=n;i++){
		dij(i,i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}

	while(q--){
		int u,v;
		cin>>u>>v;
		long long ans=LLONG_MAX;
		for(int i=0;i<e[u].size();i++){
			for(int j=0;j<e[v].size();j++){
				long long sum=e[u][i].w+e[v][j].w+dis[e[u][i].v][e[v][j].v];
				ans=min(ans,sum);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
}
I_don_t_want_to_AFO{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	I_want_to_study_OI_forever
}

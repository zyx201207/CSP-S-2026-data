#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int M=5e5+1000,N=505,I=1e16+5;
int c,n,m,d,q,w[M],dis[M],sum[N][N];
vector<pii> ve[M];
priority_queue<pii> pq;
void dij(int s){
	while(!pq.empty())pq.pop();
	for(int i=1;i<=n+m+1;i++)dis[i]=I;
	pq.push({0,s+m});dis[s+m]=0;
	while(!pq.empty()){
		pii tp=pq.top();
		pq.pop();
		int d=-tp.first,u=tp.second;
		if(d>dis[u])continue;
		for(pii k:ve[u]){
			int v=k.first,w=k.second;
			if(dis[v]>d+w){
				dis[v]=dis[u]+w;
				pq.push({-dis[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++)sum[s][i]=dis[i+m];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a,t;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			ve[m+i].push_back({a,t});
			ve[a].push_back({m+i,t});
		}
	}
	for(int i=1;i<=n;i++)dij(i);
	while(q--){
		int x,y,ans=I;
		cin>>x>>y;
		for(pii i:ve[x]){
			for(pii j:ve[y]){
				int e=i.first,f=j.first,g=i.second,h=j.second;
				ans=min(ans,sum[e-m][f-m]+g+h);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
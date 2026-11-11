#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define PII pair<int,int>
#define fi first
#define se second
const int M=5e5+5;
const int N=500;
const int inf=1e18;
int c,n,m,D,Q;
int w[M];
vector<PII>g[M+N];
int d[1005][1505];
int d1[M],d2[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(n==1){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,t;
			cin>>a>>t;
			d1[a]=t;
		}
		while(Q--){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+d1[x]+d1[y]<<endl;
		}
		return 0;
	}
	if(n==2){
		for(int i=1;i<=m;i++){
			d1[i]=d2[i]=inf;
		}
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,t;
			cin>>a>>t;
			d1[a]=t;
		}
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,t;
			cin>>a>>t;
			d2[a]=t;
		}
		int mi=inf;
		for(int i=1;i<=m;i++){
			mi=min(mi,d1[i]+d2[i]);
		}
		while(Q--){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+min({d1[x]+d1[y],d2[x]+d2[y],d1[x]+d2[y]+mi,d2[x]+d1[y]+mi})<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[m+i].push_back({a,t});
			g[a].push_back({m+i,t});
		}
	}
	if(m<=1000){
		for(int i=1;i<=n;i++){
			priority_queue<PII,vector<PII>,greater<> >q;
			q.push({0,i});
			for(int j=1;j<=m+n;j++){
				d[i][j]=inf;
			}
			d[i][i]=0;
			while(!q.empty()){
				int u=q.top().se,t=q.top().fi;
				q.pop();
				if(t>d[i][u])continue;
				for(auto x:g[u]){
					int v=x.fi,w=x.se;
					if(d[i][u]+w<d[i][v]){
						d[i][v]=d[i][u]+w;
						q.push({d[i][v],v});
					}
				}
			}
		}
		while(Q--){
			int x,y;
			cin>>x>>y;
			cout<<d[x][y]+w[x]+w[y]<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=505,M=1e6+5;
int c,n,m,d,q,w[M],a[N][N],t[N][N],dis[M];
vector<PII> g[M];
priority_queue<PII,vector<PII>,greater<PII> > pq;
int dij(int st,int ed){
	while(!pq.empty())pq.pop();
	pq.push({0,st+m});ed+=m;
	memset(dis,0x3f,sizeof dis);
	dis[st+m]=0;
	while(!pq.empty()){
		int u=pq.top().se,d=pq.top().fi;pq.pop(); 
		if(d>dis[u])continue;
		for(PII V:g[u]){
			int vv=V.fi,ww=V.se;
			if(dis[vv]>dis[u]+ww){
				dis[vv]=dis[u]+ww;
				pq.push({dis[vv],vv});
			}
		}
	}
	return dis[ed];
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i],g[i+m].pb({i,w[i]}),g[i].pb({i+m,w[i]});//i+m Õ¾Ìü->¿Ú 
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].pb({i+m+m,t[i][j]});//i+m+m ÏßÂ·->Õ¾Ìü 
			g[i+m+m].pb({a[i][j],t[i][j]});
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		cout<<dij(st,ed)<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}


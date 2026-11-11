#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
const int N=2e3+5;
int id,n,m,d,q,k[N],x[N],t[N],w[N],dis[N][N],vis[N],tot;
vector<PII> g[N];
unordered_map<int,int> mp;
struct Node{
	int id,w;
	bool operator <(const Node &a) const{
		return w>a.w; 
	} 
};
priority_queue<Node> pq;
void dij(int s){
	memset(vis,0,sizeof(vis));
	pq.push({s,0});dis[s][s]=0;
	while(!pq.empty()){
		Node t=pq.top();
		pq.pop();
		if(vis[t.id]) continue;
		vis[t.id]=1;
		for(auto i:g[t.id]){
			if(dis[s][i.fi]>dis[s][t.id]+i.se){
				dis[s][i.fi]=dis[s][t.id]+i.se;
				pq.push({i.fi,dis[s][i.fi]});
			}
		}
	}
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>id>>n>>m>>d>>q;tot=m;
	for(int i=1;i<=m;i++) cin>>w[i],mp[i]=i;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x[j]>>t[j];
			while(mp.count(x[j])) x[j]+=m;
			mp[x[j]]=++tot;
			if(j>1) g[mp[x[j-1]]].pb(make_pair(mp[x[j]],0));
		}
		for(int j=1;j<=k[i];j++){
			int xx=x[j];
			while(xx>m) xx-=m;
			g[xx].pb(make_pair(mp[x[1]],t[j]));
			g[mp[x[1]]].pb(make_pair(xx,t[j]));
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=tot;i++) dij(i);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int ii=1;ii<=k[i];ii++){
				for(int jj=1;jj<=k[j];jj++){
					if(dis[x[ii]][x[jj]]<=t[ii]+t[jj]) continue;
					g[mp[x[ii]]].pb(make_pair(mp[x[jj]],t[ii]+t[jj]));
					g[mp[x[jj]]].pb(make_pair(mp[x[ii]],t[ii]+t[jj]));				
				}
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=tot;i++) dij(i);
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<dis[l][r]+w[l]+w[r]<<"\n";
	}
	return 0;
}


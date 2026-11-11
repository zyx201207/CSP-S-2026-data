#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int,int> PII;
typedef array<int,3> ar;
const int N=2e4+5,M=1e18;
int _,n,m,d,q,w[N];
int k[N];
vector<PII> g[N];
int di[N],vis[N][505],a[N];
int mp[505][N],ans,x,y;
void dj(int s){
	queue<ar> p;
	for(int i=1;i<=n;i++){
		if(mp[i][s]!=0){
			p.push({mp[i][s],s,i});
		}
	}
	memset(vis,0,sizeof vis);
	while(p.size()){
		int u=p.front()[1],idd=p.front()[2],val=p.front()[0];
		if(u==y) ans=min(ans,val+mp[idd][u]);
		p.pop();
		if(vis[u][idd]) continue;
		vis[u][idd]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,id=g[u][i].second;
			if(id==idd){
				p.push({val,v,id});
			}
			else{
				p.push({val+mp[idd][u]+mp[id][u],v,id});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int tt;
			cin>>a[j]>>tt;
			mp[i][a[j]]=tt;
			if(j>1){
				g[a[j-1]].push_back({a[j],i});
				g[a[j]].push_back({a[j-1],i});
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=M;
		dj(x);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
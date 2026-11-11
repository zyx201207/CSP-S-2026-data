#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int nmax=1000+5;
const int mmax=1e6+5;
const int inf=1e18;
int cent,n,m,d,q,l[nmax][nmax];
int w[mmax];
vector<int> e[mmax],t[mmax];
vector<int> g[mmax],gt[nmax];
void ar(){
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			l[i][j]=inf;
	for(int i=1;i<=m;i++) l[i][i]=0;
	for(int i=1;i<=n;i++){
		int s=e[i].size();
		for(int x=0;x<s;x++)
			for(int y=0;y<s;y++){
				int u=e[i][x],v=e[i][y];
				l[u][v]=min(l[u][v],t[i][y]+t[i][x]);
				l[v][u]=min(l[v][u],t[i][x]+t[i][y]);
			}
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				l[i][j]=min(l[i][j],l[i][k]+l[k][j]);
	while(q--){
		int st,en;cin>>st>>en;
		cout<<l[st][en]+w[st]+w[en]<<endl;
	}	
}
void br(){
	int ky=t[1][0];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			l[i][j]=inf;
	for(int i=1;i<=n;i++) l[i][i]=ky*2;
	for(int i=1;i<=n;i++)
		for(int u:e[i]){
			for(int v:g[u])
				l[i][v]=l[v][i]=min(l[i][v],0ll);
			g[u].push_back(i);
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				l[i][j]=min(l[i][j],l[i][k]+l[k][j]);
	while(q--){
		int st,en;cin>>st>>en;
		int ans=inf;
		for(int u:g[st])
			for(int v:g[en])
				ans=min(ans,l[u][v]);
		cout<<ans+w[st]+w[en]<<endl;
	}
}
void cr(){
	for(int i=1;i<=n;i++)
		for(int j=0;j<e[i].size();j++){
			g[e[i][j]].push_back(i);
			gt[e[i][j]].push_back(t[i][j]);
		}	
	while(q--){
		int st,en;cin>>st>>en;
		int ans=inf;
		for(int i=0;i<g[st].size();i++)
			for(int j=0;j<g[en].size();j++)
				if(g[st][i]==g[en][j]) ans=min(ans,gt[st][i]+gt[en][j]);
				else
					for(int u=1;u<=m;u++)
						if((int)gt[u].size()==2) ans=min(ans,gt[st][i]+gt[en][j]+gt[u][0]+gt[u][1]);
		cout<<ans+w[st]+w[en]<<endl;
	}
}
void solve(){
	cin>>cent>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int s;cin>>s;
		for(int j=1;j<=s;j++){
			int x,y;cin>>x>>y;
			e[i].push_back(x);
			t[i].push_back(y);
		}
	}
	if(cent<=11) ar();
	else if(cent<=19) br();
	else cr();
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int T=1;
	while(T--)
	solve();
	
	return 0;
} 

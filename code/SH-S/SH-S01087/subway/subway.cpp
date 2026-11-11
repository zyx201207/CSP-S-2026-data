#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500+10,M=5e5+10;
struct node{
	int t,a;
};
int c,n,m,d,q;
int w[M];
vector<node> g[M];
int s[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) s[i][j]=-1;
		s[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int u,a;cin>>u>>a;
			for(int b=0;b<g[u].size();b++){
				int tt=g[u][b].t,aa=g[u][b].a;
				if(s[i][tt]==-1) s[i][tt]=a+aa;
				else s[i][tt]=min(s[i][tt],a+aa);
				s[tt][i]=s[i][tt];
			}
			g[u].push_back({i,a});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++) if(s[i][k]!=-1){
			for(int j=1;j<=n;j++) if(s[k][j]!=-1){
				if(s[i][j]==-1) s[i][j]=s[i][k]+s[k][j];
				else s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		if(x==y){
			cout<<"0\n";
			continue;
		}
		int ans=-1;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				if(ans==-1) ans=g[x][i].a+g[y][j].a+s[g[x][i].t][g[y][j].t];
				else ans=min(ans,g[x][i].a+g[y][j].a+s[g[x][i].t][g[y][j].t]);
			}
		}
		ans=ans+w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}

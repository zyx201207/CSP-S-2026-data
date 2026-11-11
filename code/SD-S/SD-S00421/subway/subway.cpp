#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
const ll INF=1e18;
int c,n,m,d,q;
ll w[N];
struct edge{
	int to;
	ll t;
};
vector<edge>s[N];
ll f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>a>>t;
			s[a].push_back({i,t});
		}
	}
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=m;i++){
		int l=s[i].size();
		for (int j=0;j<l;j++){
			for (int k=j+1;k<l;k++){
				int u=s[i][j].to,v=s[i][k].to;
				ll w=s[i][j].t+s[i][k].t;
				f[u][v]=f[v][u]=w;
			}
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while (q--){
		int u,v;
		cin>>u>>v;
		int l1=s[u].size(),l2=s[v].size();
		ll ans=INF;
		for (int i=0;i<l1;i++){
			for (int j=0;j<l2;j++){
				ans=min(ans,s[u][i].t+s[v][j].t+f[s[u][i].to][s[v][j].to]+w[u]+w[v]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

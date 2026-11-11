#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
typedef pair<int,int> PII;
int w[N],t[505][505];
vector<PII>e[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(t,0x3f,sizeof t);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;cin>>u>>w;
			e[u].push_back({i,w});
		}
	}
	for(int k=1;k<=m;k++){
		for(auto i: e[k])for(auto j: e[k]){
			int u=i.first,tu=i.second;
			int v=j.first,tv=j.second;
			if(u==v){t[u][v]=0;continue;}
			t[u][v]=t[v][u]=min(t[u][v],tu+tv);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=1e18;
		for(auto i: e[x])for(auto j: e[y]){
			int u=i.first,tu=i.second;
			int v=j.first,tv=j.second;
			ans=min(ans,w[x]+w[y]+tu+tv+t[u][v]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
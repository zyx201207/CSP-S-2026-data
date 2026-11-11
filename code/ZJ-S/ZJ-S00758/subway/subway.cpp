#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5;
int c,n,m,d,q;
int tmp[M];
struct Node{
	int v,w;
};
vector<Node>mp[M];
int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway7.in","r",stdin);
//	freopen("subway7.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>tmp[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		while(k--){
			int a,t; cin>>a>>t;
			//a<->i:t
			mp[a].push_back({i,t});
		} 
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	//add edge
	for(int u=1;u<=m;u++)
		for(int i=0;i<(int)mp[u].size();i++)
			for(int j=i+1;j<(int)mp[u].size();j++){
				int a=mp[u][i].v,b=mp[u][j].v,c=mp[u][i].w+mp[u][j].w;
				//mp[u][i].v<->mp[u][j].v:mp[u][i].w+mp[u][j].w
				dis[a][b]=dis[b][a]=min(dis[a][b],c);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int s,t,ans=1e18; cin>>s>>t;
		for(Node nodes:mp[s])
			for(Node nodet:mp[t])
				ans=min(ans,nodes.w+nodet.w+dis[nodes.v][nodet.v]);
		cout<<ans+tmp[s]+tmp[t]<<"\n";
	}
	return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,time;
};
const int N=5e5+5;
int c,n,m,d,q,s,t,ans,w[N],vis[405][55];
bool h[505];
vector<node>v[505];
void dfs(int x,int cost){
	if(x==t){ans=min(ans,cost);return;}
	for(int i=1;i<=n;i++){
		if(vis[x][i]==0) continue;
		h[x]=1;
		for(auto j:v[i]){
			if(j.x==x||h[j.x]) continue;
			dfs(j.x,cost+j.time+vis[x][i]);
		}h[x]=0;
	}
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,y;j<=k;j++){
			cin>>x>>y;vis[x][i]=y;
			v[i].push_back({x,y});
		}
	}
	while(q--){
		cin>>s>>t;ans=1e18;
		memset(h,0,sizeof(h));
		dfs(s,0);
		cout<<ans+w[s]+w[t]<<"\n";
	}
	return 0;
}

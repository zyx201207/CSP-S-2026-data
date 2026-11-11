#include<iostream>
#include<cstring>
#include<vector> 
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,w[N],t[510][510];
vector<pii> bel[N];
struct station{int l[21],t[21],tot;}st[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			st[a].tot++;
			st[a].l[st[a].tot]=i;
			st[a].t[st[a].tot]=t;
			bel[a].push_back({i,t});
		}
	}
	memset(t,0x3f,sizeof(t));
	for(int i=1;i<=n;i++) t[i][i]=0;
	for(int p=1;p<=m;p++){//Õ¾µã 
		int k=st[p].tot;
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				if(i==j) continue;
				int u=st[p].l[i],v=st[p].l[j];
				t[u][v]=min(t[u][v],st[p].t[i]+st[p].t[j]);
				t[v][u]=min(t[v][u],st[p].t[i]+st[p].t[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
				t[j][i]=min(t[j][i],t[i][k]+t[k][j]);
			}
		}
	}
	while(q--){
		int u,v,ans=0x3f3f3f3f3f3f3f3f;cin>>u>>v;
		for(auto i:bel[u]){
			for(auto j:bel[v]){
				//cout<<i<<' '<<j<<'\n';
				ans=min(ans,t[i.fi][j.fi]+i.se+j.se);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}


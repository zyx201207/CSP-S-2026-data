#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,d,q,c,w[N],mp[600][600];
struct node{
	int to,w;
};
vector<node>G[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int a,t;
			cin>>a>>t;
			G[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			mp[i][j]=1e16;
		}
		mp[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		for(auto t:G[i]){
			for(auto tt:G[i]){
				if(t.to==tt.to)continue;
				mp[t.to][tt.to]=min(mp[t.to][tt.to],t.w+tt.w);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e16;
		for(auto t:G[x]){
			for(auto tt:G[y]){
				ans=min(ans,mp[t.to][tt.to]+t.w+tt.w+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

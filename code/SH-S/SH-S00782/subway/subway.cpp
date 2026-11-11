#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=505,M=5e5+5,D=25;
int c,n,m,d,q;
ll w[M];
ll g[N][N];
vector<pair<int,ll>> t[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(0);
	
	memset(g,0x3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		t[i].reserve(16);
	}
	for(int i=1;i<=n;i++){
		g[i][i]=0;
		int k;cin>>k;
		while(k--){
			int a;ll ti;cin>>a>>ti;
			t[a].push_back({i,ti});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto pu:t[i]){
			for(auto pv:t[i]){
				g[pu.first][pv.first]=min(g[pu.first][pv.first],pu.second+pv.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=0x3f3f3f3f3f3f3f3fll;
		for(auto pu:t[x]){
			for(auto pv:t[y]){
				ans=min(ans,g[pu.first][pv.first]+pu.second+pv.second);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	
	cout<<flush;
	return 0;
}

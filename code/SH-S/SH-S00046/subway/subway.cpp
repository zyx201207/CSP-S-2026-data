#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500010],e[510][510];
vector<pair<int,int> > lc[510],con[500010],E[510];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i = 1; i <= m; i++) cin>>w[i];
	for (int i = 1; i <= n; i++){
		int k;
		cin>>k;
		for (int j = 1; j <= k; j++){
			int x,t;
			cin>>x>>t;
			lc[i].push_back({x,t});
			con[x].push_back({i,t});
		}
	}
	memset(e,0x3f,sizeof e);
	for (int i = 1; i <= n; i++){
		e[i][i]=0;
		for (auto x:lc[i]){
			int sta=x.first,cst=x.second;
			for (auto y:con[sta]){
				int j=y.first,cst2=y.second;
				e[i][j]=min(e[i][j],cst+cst2);
			}
		}
	}
	int cnt=0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cnt+=(e[i][j]!=0x3f3f3f3f3f3f3f3f);
		}
	}
//	cout<<cnt<<"\n";
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	while (q--){
		int u,v,ans=0x3f3f3f3f3f3f3f3f;
		cin>>u>>v;
		for (auto x:con[u]){
			for (auto y:con[v]){
				ans=min(ans,e[x.first][y.first]+x.second+y.second);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
/*
w不需要管
首先，必须把图转化为树，那么就得看如何转化为树
必须找到如何建出树
也许并不需要？
20^2*10^5可以接受
也就是说，求出转乘的代价即可！这是重大突破
u->v，需要找到这两个线路之间有哪些共用地铁站
那么，先枚举每个地铁站，看看每个地铁站哪些线路经过，两两连边  68分
枚举每个线路对应的地铁站（5*10^5），再枚举那个地铁站的20个可达线路，不就行了？
*/ 

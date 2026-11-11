/*
1.25e8
我相信跑不满 
我相信CCF神机 
如果能 AC 的话，那我也算是初二能在CSP中取得200pts了 
qwq
哦对了，如果你读到了这个，我猜你是在做迷惑行为大赏 
你可以去看看CSPS2025我写的CSP之歌  
辛苦了awa   
我的flody是不是拼错了 
这不重要  
*/
#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
constexpr int N=1e6+10;
constexpr int M=1010;
int cas,n,m,d,q;
int w[N];
int f[M][M];
struct node{
	int to,w;
};
vector<node> v[N];
void flody(){
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	} 
}
int ans;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>cas>>n>>m>>d>>q;
	for (int i=1; i<=m; i++) cin>>w[i];
	for (int i=1; i<=n; i++){
		int k;
		cin>>k;
		for (int j=1; j<=k; j++){
			int u,t;
			cin>>u>>t;
			v[u].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof f);
	for (int i=1; i<=m; i++){
		for (auto ita:v[i]){
			for (auto itb:v[i]){
				if (ita.to==itb.to) continue;
				f[ita.to][itb.to]=f[itb.to][ita.to]=min(f[ita.to][itb.to],ita.w+itb.w);
			}
		}
	}
	for (int i=1; i<=n; i++){
		f[i][i]=0;
	}

	flody();
//	for (int i=1; i<=n; i++){
//		for (int j=1; j<=n; j++){
//			cerr<<f[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	while (q--){
		int x,y;
		cin>>x>>y;
		ans=LLONG_MAX;
		for (auto ita:v[x]){
			for (auto itb:v[y]){
				ans=min(ans,f[ita.to][itb.to]+ita.w+itb.w+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


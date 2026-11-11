#include <bits/stdc++.h>
using namespace std;
#define int long long
#define CK cerr<<"\n"<<1.0*fabs(&ED-&ST)/1024/1024<<"MB\n";
bool ST;
const int N=505,M=500010,INF=1e17;
int c,n,m,d,q;
int w[M],ds[N][N],k[N],st,ed;
int aa,tt;
vector<array<int,2> >jl[M];
int ans;
bool ED;
signed main(){
//	freopen("subway7.in","r",stdin);
//	freopen("subway.out","w",stdout);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			ds[i][j]=INF;
		}
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>aa>>tt;
			for(auto to:jl[aa]){
				if(ds[to[0]][i]>tt+to[1]){
					ds[to[0]][i]=ds[i][to[0]]=tt+to[1];
				}
			}
			jl[aa].push_back({i,tt});
		}
	}
	for(int i=1;i<=n;++i) ds[i][i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j){
				continue;
			}
			for(int p=1;p<=n;++p){
				ds[j][p]=min(ds[j][p],ds[j][i]+ds[i][p]);
			}
		}
	}
	for(int i=1;i<=q;++i){
		cin>>st>>ed;
		if(st==ed){
			cout<<0<<'\n';
			continue;
		}
		ans=INF;
		for(auto to:jl[ed]){
			for(auto jj:jl[st]){
				ans=min(ans,jj[1]+ds[jj[0]][to[0]]+to[1]+w[st]+w[ed]);
			}
		}
		cout<<ans<<'\n';
	}
//	CK
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

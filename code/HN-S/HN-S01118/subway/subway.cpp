#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2+10;
const int M = 5e5+10;
const int inf = 2e18;
int c,n,m,d,q,u,v,w[M],k[N],mp[N][N];
vector<int>t[N];
struct E{
	int i,j;
};
vector<E>e[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];++j){
			cin>>x>>y;
			t[i].emplace_back(y);
			e[x].emplace_back((E){i,j-1});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i!=j)mp[i][j]=inf;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<e[i].size();++j){
			for(int l=0;l<e[i].size();++l){
				if(j==l)continue;
				mp[e[i][j].i][e[i][l].i]=min(mp[e[i][j].i][e[i][l].i],t[e[i][j].i][e[i][j].j]+t[e[i][l].i][e[i][l].j]);
			}
		}
	}//O(md^2)
	for(int l=1;l<=n;++l){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				mp[i][j]=min(mp[i][l]+mp[l][j],mp[i][j]);
			}
		}
	}
	while(q--){
		cin>>u>>v;
		int ans=inf;
		for(int i=0;i<e[u].size();++i){
			for(int j=0;j<e[v].size();++j){
				ans=min(mp[e[u][i].i][e[v][j].i]+t[e[u][i].i][e[u][i].j]+t[e[v][j].i][e[v][j].j],ans);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
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

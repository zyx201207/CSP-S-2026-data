#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,q,w[N],k[510][510],ans,sum;
bool vis[N];
struct f{
	long long u,w;
};
vector <f> v[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a,t;
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) k[i][j]=1e18;
		k[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<v[i].size();j++){
			for(int l=0;l<j;l++){
				k[v[i][j].u][v[i][l].u]=min(k[v[i][j].u][v[i][l].u],v[i][j].w+v[i][l].w);
				k[v[i][l].u][v[i][j].u]=min(k[v[i][l].u][v[i][j].u],v[i][j].w+v[i][l].w);
			}
		}
	}
	for(int K=1;K<=n;K++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				k[i][j]=min(k[i][K]+k[K][j],k[i][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				ans=min(ans,k[v[x][i].u][v[y][j].u]+w[x]+w[y]+v[x][i].w+v[y][j].w); 
			}
		}
		cout<<ans<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

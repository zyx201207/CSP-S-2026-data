#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+10,N=510;
const ll inf=1e18;
int c,n,m,d,q,w[M],k,a,t;
ll f[N][N],ans;
vector<pair<int,ll> > sta[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) 
			f[i][j]=inf;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			sta[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u:sta[i])
			for(auto v:sta[i]){
//				cout<<u.first<<" "<<v.first<<"\n";
				f[u.first][v.first]=min(f[u.first][v.first],u.second+v.second);
			}
	}
	for(int p=1;p<=n;p++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][p]+f[p][j],f[i][j]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			if(f[i][j]!=inf)cout<<i<<" "<<j<<" "<<f[i][j]<<" ";
//		cout<<"\n";
//	}
	for(int i=1,x,y;i<=q;i++){
		ans=inf;
		cin>>x>>y;
		for(auto u:sta[x])
			for(auto v:sta[y])
				ans=min(u.second+v.second+f[u.first][v.first],ans);
		cout<<ans+w[x]+w[y]<<'\n';
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
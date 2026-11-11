#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
ll dis[N][N],w[M];
vector<pair<int,ll>> p[M];
void floyd(int n){
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++){
		if(dis[i][j]>dis[i][k]+dis[j][k])
			dis[i][j]=dis[i][k]+dis[j][k];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(dis,0x3f,sizeof(dis));

	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;ll w;
			cin>>x>>w;
			p[x].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto l:p[i])
		for(auto r:p[i])
			dis[l.first][r.first]=dis[r.first][l.first]=l.second+r.second;
	}
	floyd(n);
	
	while(q--){
		int s,t;
		cin>>s>>t;
		ll ans=1e18;
		for(auto l:p[s])
		for(auto r:p[t])
			ans=min(ans,dis[l.first][r.first]+l.second+r.second);
		cout<<ans+w[s]+w[t]<<endl;
	}
	return 0;
}


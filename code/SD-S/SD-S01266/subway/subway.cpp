#include<bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 505;
const int M = 5e5+5;
long long dis[N][N];
int w[M];
vector<pair<int,int> > stt[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k,dis[i][i] = 0;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			stt[a].emplace_back(i,t);
		}
	}
	for(int i=1;i<=m;i++) for(int j=1;j<stt[i].size();j++) for(int l=0;l<j;l++){
		int a1 = stt[i][j].first,t1 = stt[i][j].second;
		int a2 = stt[i][l].first,t2 = stt[i][l].second;
		dis[a2][a1] = dis[a1][a2] = min(dis[a1][a2],(long long)t1+t2);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j] = dis[i][k]+dis[k][j];
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans = INF;
		for(auto& i : stt[x]) for(auto& j : stt[y]) ans = min(ans,dis[i.first][j.first]+i.second+j.second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

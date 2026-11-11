#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long c,n,m,d,q;
long long zhan[N],ct[N];
long long w[N];
long long dis[1005][1005];
vector<pair<long long,long long> > g[1005];
void init(){
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>zhan[j]>>ct[j];
		}
		for(long long j=1;j<k;j++){
			for(long long t=j+1;t<=k;t++){
				g[zhan[j]].push_back({zhan[t],ct[j]+ct[t]});
				g[zhan[t]].push_back({zhan[j],ct[j]+ct[t]});
			}
		}
	}
}
// floyd
void solve1(){
	memset(dis,0x3f,sizeof(dis));
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<(long long)g[i].size();j++){
			long long v=g[i][j].first,w=g[i][j].second;
			dis[i][v]=min(dis[i][v],w);
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=m;j++){
			for(long long k=1;k<=m;k++){
				if(i!=j&&i!=k&&j!=k){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	while(q--){
		long long u,v;
		cin>>u>>v;
		cout<<dis[u][v]+w[u]+w[v]<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	init();
	solve1();
	
	
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
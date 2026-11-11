#include<bits/stdc++.h>
using namespace std;
const long long N=520,M=5e5+7;
long long C,n,m,d,q;
long long w[M];
long long siz[N],a,t;
vector<pair<long long,long long>> line[M];
long long dis[N][N];
void floyd(){
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>C>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>siz[i];
		for(long long j=1;j<=siz[i];j++){
			cin>>a>>t;
			line[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(long long i=1;i<=n;i++) dis[i][i]=0;
	for(long long i=1;i<=m;i++){
		long long vs=line[i].size();
		for(long long j=0;j<vs;j++){
			for(long long k=j+1;k<vs;k++){
				long long l1=line[i][j].first,l2=line[i][k].first;
				long long t1=line[i][j].second,t2=line[i][k].second;
				dis[l1][l2]=min(dis[l1][l2],t1+t2);
				dis[l2][l1]=min(dis[l2][l1],t1+t2);
			}
		}
	}
	floyd();
	while(q--){
		long long x,y,ans=1e18;
		cin>>x>>y;
		for(auto i:line[x]){
			for(auto j:line[y]){
				ans=min(ans,dis[i.first][j.first]+i.second+j.second);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	
	return 0;
}

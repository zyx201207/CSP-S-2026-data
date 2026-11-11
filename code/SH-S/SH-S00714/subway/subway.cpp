#include<bits/stdc++.h>
using namespace std;
#define N 508
#define M 500008
unsigned long long dist[N][N];
int n,m,c,d,q,w[M],k[N];
struct cnst{
	int nd;
	unsigned long long t;
	friend bool operator<(cnst x,cnst y){
		return x.nd<y.nd;
	}
}b[M][22];
int cnt[M];
unsigned long long res,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>x>>y,b[x][++cnt[x]]={i,y};
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=(i==j?0:LLONG_MAX/2);
	for(int i=1;i<=m;i++){
		sort(b[i]+1,b[i]+cnt[i]+1);
		for(int j=1;j<=cnt[i];j++) for(int o=1;o<j;o++){
			dist[b[i][j].nd][b[i][o].nd]=min(dist[b[i][j].nd][b[i][o].nd],b[i][j].t+b[i][o].t);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) dist[j][i]=dist[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int o=1;o<=n;o++) dist[i][j]=min(dist[i][j],dist[i][o]+dist[o][j]);
	while(q--){
		cin>>x>>y;res=LLONG_MAX;
		for(int i=1;i<=cnt[x];i++) for(int j=1;j<=cnt[y];j++) res=min(res,dist[b[x][i].nd][b[y][j].nd]+b[x][i].t+b[y][j].t);
		res+=w[x]+w[y];
		cout<<res<<'\n';
	}
	return 0;
}

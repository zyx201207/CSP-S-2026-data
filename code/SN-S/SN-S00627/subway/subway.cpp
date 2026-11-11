#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+10,inf=1e18;
int kkksc03;//测试点 
int n;//线路 
int m;//站台
int d;//每个点最多经过多少个地铁线路 
int q;//询问个数 
int www[M];//每个站点强制花费
int e[N][N];
vector<pair<int,int> >line[M];//经过这个点的所有地铁线 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>kkksc03>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)e[i][j]=inf;
	for(int i=1;i<=m;i++)cin>>www[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int a,t;cin>>a>>t;
			line[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(pair<int,int>p:line[i]){
			for(pair<int,int>q:line[i]){
				e[p.first][q.first]=min(e[p.first][q.first],p.second+q.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
		}
	}
	while(q--){
		int s,t;cin>>s>>t;
		int ans=inf;
		for(pair<int,int>p:line[s]){
			for(pair<int,int>q:line[t]){
				ans=min(ans,e[p.first][q.first]+p.second+q.second+www[s]+www[t]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;long long _,n,m,D,q,w[M],dis[N][N],ans=0;vector<pair<int,long long> > d[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>_>>n>>m>>D>>q;for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=(i==j?0:5e17+7);
	for(long long i=1,kkk,x,y;i<=n;i++){
		cin>>kkk;while(kkk--){
			cin>>x>>y;for(auto j:d[x]) dis[i][j.first]=min(dis[i][j.first],y+j.second);//,cout<<i<<" "<<j.first<<":"<<y+j.second<<"\n";
			d[x].push_back({i,y});
		}
	}for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[j][i]);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int x,y;while(q--){
		cin>>x>>y,ans=1e18+7;for(auto i:d[x]) for(auto j:d[y]) ans=min(ans,dis[i.first][j.first]+i.second+j.second);
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}

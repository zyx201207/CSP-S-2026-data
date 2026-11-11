#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define mkp(a,b) make_pair(a,b)
using namespace std;
const int N=505,M=5e5+5;
int C,n,m,d,q;
int dis[N][N],val[M];
vector<pii> vec[M];
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>val[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			vec[x].push_back(mkp(i,y));
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int t=1;t<=m;t++){
		int len=vec[t].size();
		for(int i=0;i<len;i++)
			for(int j=i+1;j<len;j++){
				int x=vec[t][i].first,y=vec[t][j].first;
				dis[x][y]=dis[y][x]=min(dis[x][y],vec[t][i].second+vec[t][j].second);
			}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dis[i][k]==INF) continue;
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=INF;
		for(pii w1:vec[x]){
			for(pii w2:vec[y]){
				int w=dis[w1.first][w2.first]+w1.second+w2.second;
				ans=min(ans,w);
			}
		}
		ans+=val[x]+val[y];
		cout<<ans<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=500100,N=510;
int c,n,m,d,q,w[M],f[N][N];
vector<pair<int,int> >p[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		int num;cin>>num;
		while(num--){
			int a,t;cin>>a>>t;
			p[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int siz=p[i].size();
		for(int t1=0;t1<siz;t1++){
			for(int t2=t1+1;t2<siz;t2++){
				int x=p[i][t1].first,y=p[i][t2].first;
				f[x][y]=min(f[x][y],p[i][t1].second+p[i][t2].second);
				f[y][x]=min(f[y][x],p[i][t1].second+p[i][t2].second);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y,ans=2e12;cin>>x>>y;
		for(auto t1:p[x])
			for(auto t2:p[y])
				ans=min(ans,f[t1.first][t2.first]+t1.second+t2.second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

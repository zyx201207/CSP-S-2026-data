#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
const int N=5e2+5,M=5e5+5;
int w[M],dist[N][N];
vector<PII> v[M];
int c,n,m,d,q;
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		for(int j=1;j<=s;j++){
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++) dist[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			int j1=v[i][j].x,j2=v[i][j].y;
			for(int k=0;k<v[i].size();k++){
				int k1=v[i][k].x,k2=v[i][k].y;
				if(j1!=k1){
					dist[j1][k1]=dist[k1][j1]=min(dist[j1][k1],j2+k2);
				}
			}
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		int minn=1e18;
		for(int i=0;i<v[x].size();i++){
			int i1=v[x][i].x,i2=v[x][i].y;
			for(int j=0;j<v[y].size();j++){
				int j1=v[y][j].x,j2=v[y][j].y;
				minn=min(minn,dist[i1][j1]+i2+j2);
			}
		}
		ans+=minn;
		cout<<ans<<"\n";
	}
	return 0;
}
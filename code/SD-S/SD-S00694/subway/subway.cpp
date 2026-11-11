#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=505,M=5e5+5,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[M],a[N][N];
vector<pii> vec[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,op;i<=n;i++){
		cin>>op;
		for(int j=1,x,y;j<=op;j++){
			cin>>x>>y;
			vec[x].push_back(mp(i,y));
		}
	}
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size();j++)
			for(int k=0;k<vec[i].size();k++){
				int x=vec[i][j].fi,y=vec[i][k].fi;
				a[x][y]=min(a[x][y],vec[i][j].se+vec[i][k].se);
			}
	}
	for(int i=1;i<=n;i++) a[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		int res=INF;
		for(int j=0;j<vec[x].size();j++)
			for(int k=0;k<vec[y].size();k++)
				res=min(res,vec[x][j].se+vec[y][k].se+a[vec[x][j].fi][vec[y][k].fi]);
		cout<<res+w[x]+w[y]<<'\n';
	}
	return 0;
} 

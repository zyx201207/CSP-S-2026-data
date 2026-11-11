#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define _(x,y) (x=min(x,y))
const int N=5e5+5;
const int M=505;
int c,n,m,d,Q;
struct BF{
	int w[N],d[M][M];
	vector<int>t[N],pa[N];
	void solve(){
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1,k;i<=n;i++){
			cin>>k;
			for(int j=1,A,T,lst=0;j<=k;j++){
				cin>>A>>T;
				t[A].pb(T),pa[A].pb(i);
			}
		}
		memset(d,0x3f,sizeof d);
		for(int i=1;i<=m;i++)
			for(int a=0;a<pa[i].size();a++)for(int b=0;b<pa[i].size();b++)if(a^b)
				_(d[pa[i][a]][pa[i][b]],t[i][a]+t[i][b]);
		for(int i=1;i<=n;i++)d[i][i]=0;
		for(int o=1;o<=n;o++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					_(d[i][j],d[i][o]+d[o][j]);
				}
			}
		}
		for(int i=1,x,y;i<=Q;i++){
			cin>>x>>y;int rs=4e18;
			for(int a=0;a<pa[x].size();a++)for(int b=0;b<pa[y].size();b++){
				rs=min(rs,d[pa[x][a]][pa[y][b]]+t[x][a]+t[y][b]);
			}
			cout<<rs+w[x]+w[y]<<'\n';
		}
	}
}_;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	_.solve();
	return 0;
}


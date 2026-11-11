#include<bits/stdc++.h>
#define fir first
#define sec second
#define int long long
#define pii pair<int,int>
#define tomin(a,b) a=min(a,b)
#define tomax(a,b) a=max(a,b)
#define fep(i,s,e) for(int i=s;i<e;i++)
#define pef(i,s,e) for(int i=s;i>e;i--)
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define per(i,s,e) for(int i=s;i>=e;i--)
using namespace std;
const int N=505;
const int K=5e5+5;
const int M=5e5+5;
const int inf=1e18;
int c,n,m,d,q;
int w[M],k[N];
vector<pii>t[N],s[M];
int f[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)cin>>w[i];
	rep(i,1,n){
		cin>>k[i];
		rep(j,1,k[i]){
			int u,v;cin>>u>>v;
			t[i].push_back({u,v});
			s[u].push_back({i,v});
		}
	}
	rep(i,1,n)rep(j,1,n)if(i!=j)f[i][j]=inf;
	rep(i,1,m){
		fep(l,0,s[i].size()){
			fep(r,l+1,s[i].size()){
				int dis=s[i][l].sec+s[i][r].sec;
				int L=s[i][l].fir,R=s[i][r].fir;
				f[L][R]=f[R][L]=dis;
			}
		}
	}
	rep(mid,1,n){
		rep(i,1,n){
			rep(j,1,n){
				tomin(f[i][j],f[i][mid]+f[mid][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=inf;
		fep(i,0,s[x].size()){
			int l=s[x][i].fir;
			int L=s[x][i].sec;
			fep(j,0,s[y].size()){
				int r=s[y][j].fir;
				int R=s[y][j].sec;
				tomin(ans,w[x]+w[y]+L+R+f[l][r]);
			}
		}
		cout<<ans<<"\n";
	}
}
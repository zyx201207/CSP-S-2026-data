#include<bits/stdc++.h>

using namespace std;

#define int long long

#define rp(i,j,k) for(int i=(j);i<=(k);i++)
#define pr(i,j,k) for(int i=(j);i>=(k);i--)
#define vi vector<int>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
void gmin(int &x,int y){x=min(x,y);}
void gmax(int &x,int y){x=max(x,y);}

namespace SOLVE{

const int N=505;
const int M=5e5+5;
const int inf=1e18;
int c,n,m,d,q;
int w[M],f[N][N];
vector<pii>s[M];

void solve(){
	cin>>c>>n>>m>>d>>q;
	rp(i,1,m)
		cin>>w[i];
	rp(i,1,n){
		int k;cin>>k;
		while(k--){
			int v,w;
			cin>>v>>w;
			s[v].eb(i,w);
		}
	}
	rp(i,1,n)
		rp(j,1,n)f[i][j]=inf;
	rp(i,1,n)
		f[i][i]=0;
	rp(i,1,m)
		rp(x,0,(int)s[i].size()-1)
			rp(y,0,(int)s[i].size()-1)
				if(x!=y)gmin(f[s[i][x].fi][s[i][y].fi],s[i][x].se+s[i][y].se);
	rp(k,1,n)
		rp(i,1,n)
			rp(j,1,n)
				if(i!=j&&i!=k&&j!=k)
					gmin(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y,ans=inf;
		cin>>x>>y;
		rp(i,0,(int)s[x].size()-1)
			rp(j,0,(int)s[y].size()-1)
				gmin(ans,f[s[x][i].fi][s[y][j].fi]+s[x][i].se+s[y][j].se);
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return;
}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _=1;//cin>>_;
	while(_--)SOLVE::solve();
	return 0;
}

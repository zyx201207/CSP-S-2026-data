#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(z);x>=(z);x--)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvi vector<vi>
#define eb emplace_back
#define emp emplace
#define pob pop_back
#define beg begin
#define all(x) beg(x),end(x)
#define allt(x,y,z) beg(x)+y,beg(x)+z
#define ld long double
#define ull unsigned long long
#define y1 waefefwefidsvbu
#define inf INT_MAX
#define linf LLONG_MAX
#define debug(x) cerr<<" debug at line "<<__LINE__<<": "#x"="<<(x)<<"\n";
//-D_GLIBCXX_DEBUG
#define fi first
#define se second
#define tomn(x,y) x=min(x,y)
/*
O(n^3+md^2+qd^2)
这个w是和一位
我能写对floyd吗 
*/
int C,n,m,d,q;
#define N 505
#define M 500005
int w[M];
vector<pair<int,int>> de[M];
int f[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
//	debug(n);
	rep(i,1,m){
		cin>>w[i];
	}
	rep(i,1,m) de[i].reserve(d);
	rep(i,1,n){
		int k;
		cin>>k;
		for(;k--;){
			int a,t;
			cin>>a>>t;
//			assert(a<M);
			de[a].eb(i,t);
		}
	}
	rep(i,1,n) rep(j,1,n){
		f[i][j]=(i==j)?0:(linf/3);
	}
	rep(i,1,m){ 
		for(size_t x=0;x<de[i].size();x++){
			for(size_t y=x+1;y<de[i].size();y++){ 
				tomn(f[de[i][x].fi][de[i][y].fi],de[i][x].se+de[i][y].se);
				tomn(f[de[i][y].fi][de[i][x].fi],de[i][x].se+de[i][y].se);
			}
		}
	} 
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				tomn(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}  
	rep(i,1,q){
		int u,v;
		cin>>u>>v;
		int ans=linf/2;
		for(size_t x=0;x<de[u].size();x++){
			for(size_t y=0;y<de[v].size();y++){
				tomn(ans,f[de[u][x].fi][de[v][y].fi]+de[u][x].se+de[v][y].se);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";;
	}
}
/*

*/


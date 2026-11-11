#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
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
/*
per wrong!!!
*/
#define N 2000006
int C,_;
int n,d;
namespace sub1{
	bool check(){
		return n<=300;
	}
	vi g[N];
	int X[N];
	int dis[N];
	int cnt[N];
	int nx[N];
	int pr[N];
	int tot[N];
	vi tr[N]; 
	int f1[N];//直着走下来的 
	int f2[N];//在这一步走到+1的 
	int f3[N];// 
	int f4[N];//
	int f5[N];//
	int res[N];
	void dfs(int u,int fa){
//		cerr<<"DFS("<<u<<","<<fa<<")\n"; 
		if(fa==0){
			f1[u]=0;
		}else{
//			f1[u]=f1[fa];
			if(nx[fa]==u){
				f1[u]=f1[fa]+tot[fa];
			}
//			f1[u]+=(nx[fa]==u);
		}
		if(fa==0){
			
		}else{
			if(nx[u]==u+1){
				;
			}else if(nx[fa]==u+1){
				f2[u]=f1[fa]+tot[fa];
			}
			f2[u]+=tot[u+1];
		}
		if(fa){
			if(nx[fa]==u){
				f3[u]+=f3[fa]; 
			}
			if(nx[fa+1]==u){
				if(u!=fa+1) f3[u]+=f2[fa];
			}
		} 
//		debug(nx[fa]);
		if(nx[fa]>u&&u!=fa+1){
			f5[u]+=f2[fa];
//			cerr<<"f5["<<u<<"]="<<f2[fa]<<"\n";
		}
//		if(fa&&nx[fa+1]>u&&u!=fa+1){
//			f5[u]+=f2[fa];
//		}
//		if(fa&&nx[fa+1]==u&&u!=fa+1){
//			f4[u]+=f2[fa];
//		}
//		if(fa&&){
//			f4[u]+=f4[u];
//		}
//		if(fa&&nx[fa]>u){
//			f5[u]+=f4[fa];
//		}
//		if(fa&&fa+1!=u&&nx[fa]>u){
//			f5[u]+=f2[fa];
//		}
		if(fa&&nx[fa]+1==u&&fa+1!=u){
			f4[u]+=f2[fa];
		}
		if(fa&&nx[fa]==u){
			f4[u]+=f4[fa];
		}
		if(fa&&nx[fa]>u){
			f5[u]+=f4[fa];
		}
		for(int v:tr[u]){
			dfs(v,u);
		}
	}
	void solve(){
		for(;_--;){ 
			int ans=0;
			cin>>n>>d;
			rep(i,1,n) cin>>X[i];
			rep(i,1,n){
				rep(j,1,n){
					if(abs(X[i]-X[j])<=d){
						pr[i]=j;
						break;
					}
				}
				per(j,n,1){
					if(abs(X[i]-X[j])<=d){
						nx[i]=j;
						tot[j]++;
						break;
					}
				}
			} 
			rep(i,1,n){
				if(pr[i]!=i) tr[pr[i]].eb(i);
			}
			rep(i,1,n){
				if(pr[i]==i){
					dfs(i,0);
				}
			}
			per(y,n,1){ 
				vi v;
				int p=y; 
				for(;;){
					v.eb(p); 
					if(p==pr[p]) break;
					p=pr[p];
				}
				reverse(all(v));
				int res=0; 
				for(size_t i=0;i+2<v.size();i++){ 
					if(v[i+1]==v[i]+1) continue;
					p=v[i]+1;
					for(size_t j=i+1;j<v.size();j++){ 
						if(nx[p]==y&&j+1==v.size()){
							p=-1;
							break;
						} 
						if(min(nx[p],y)!=v[j]){
							p=-1;
							break;
						}
						p=v[j];
					} 
					if(p==-1) continue; 
					res+=f2[v[i]]; 
				}
				res+=f3[y];
				if(v.size()>=2){ 
					int fa=v[v.size()-2];
					int u=y;
					if(u!=fa+1&&fa){
						if(nx[fa+1]!=y){
							if(min(nx[fa],y)==y){
								res+=f2[fa];
							}
						}
					}
				} 
				ans+=res; 
			} 
			cout<<ans<<"\n";
			rep(i,1,n) tot[i]=0,tr[i].clear();
			rep(i,1,n) f1[i]=f2[i]=res[i]=0;
			rep(i,1,n) f3[i]=f4[i]=f5[i]=0,nx[i]=pr[i]=0;
			//qk
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>_;
	sub1::solve();
}
/*
0 1
5 2
1 2 3 4 5



0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/


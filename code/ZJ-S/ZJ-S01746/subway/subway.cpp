#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
#define For(i,l,r) for(int i=(l);i<=(r);++i)
#define Rof(i,l,r) for(int i=(l);i>=(r);--i)
bool M_S;
namespace cjr2010{
	const int N=505;
	const int M=(int)(5e5+5);
	int SUB,n,m,d,q;
	int w[M];
	
	int c[N];
	vector<int> a[N],t[N];

	vector<array<int,2>> b[M];
	int dis[N][N];

	void MAIN(){
		cin>>SUB>>n>>m>>d>>q;
		For(i,1,m) cin>>w[i];
		For(i,1,n){
			cin>>c[i];
			vector<int>(c[i]+1).swap(a[i]);
			vector<int>(c[i]+1).swap(t[i]);
			For(j,1,c[i]){
				cin>>a[i][j]>>t[i][j];
				b[a[i][j]].push_back({i,t[i][j]});
			}
		}
		For(i,1,n){
			For(j,1,n){
				if(i==j) dis[i][j]=0;
				else dis[i][j]=inf;
			}
		}
		For(i,1,m){
			for(array<int,2> j:b[i]){
				for(array<int,2> k:b[i]){
					dis[j[0]][k[0]]=min(dis[j[0]][k[0]],j[1]+k[1]);
				}
			}
		}
		For(k,1,n){
			For(i,1,n){
				For(j,1,n){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		For(_,1,q){
			int x,y;cin>>x>>y;
			int ans=inf;
			for(array<int,2> i:b[x]){
				for(array<int,2> j:b[y]){
					ans=min(ans,i[1]+dis[i[0]][j[0]]+j[1]);
				}
			}
			cout<<ans+w[x]+w[y]<<"\n";
		}
	}
}
bool M_T;
signed main(){
	// freopen("subway7.in","r",stdin),freopen(".out","w",stdout);
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	double T_S=clock();cjr2010::MAIN();double T_T=clock();
	cerr<<(T_T-T_S)/CLOCKS_PER_SEC<<"s\n";
	cerr<<(&M_S-&M_T)/1048576.0<<"MiB\n";
	return 0;
}
/*
subway
g++ 1.cpp -o 1 -O2 -std=c++14 -static
*/
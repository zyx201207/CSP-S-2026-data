#include<bits/stdc++.h>
#define IOS cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define ll long long
#define db double 
#define pb push_back
#define eb emplace_back
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memset(x,y,sizeof(x))
#define PII pair<int,int>
#define PIL pair<int,ll>
#define lb(x) ((x)&(-x))
using namespace std;
const int N=5e5+20,M=500+20;
const ll INF=1e18,mod=998244353;
namespace H_H{
	int c,n,m,d,q;
	ll w[N],f[M][M];
	vector<PIL> to[N];
	int main(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1,k;i<=n;i++){
			cin>>k;
			for(int j=1,x,t;j<=k;j++){
				cin>>x>>t;
				to[x].eb(i,t);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i^j) f[i][j]=INF;
			}
		}
		for(int i=1;i<=m;i++){
			for(auto X:to[i]){
				int x=X.first;ll tx=X.second;
				for(auto Y:to[i]){
					int y=Y.first;ll ty=Y.second;
					f[x][y]=min(f[x][y],tx+ty);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		for(int i=1,u,v;i<=q;i++){
			cin>>u>>v;
			ll ans=INF;
			for(auto X:to[u]){
				int x=X.first;ll tx=X.second;
				for(auto Y:to[v]){
					int y=Y.first;ll ty=Y.second;
					ans=min(ans,f[x][y]+tx+ty);
				}
			}
			cout<<ans+w[u]+w[v]<<"\n";
		}
		return 0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IOS;H_H::main();
	// cerr<<(db)clock()/CLOCKS_PER_SEC<<"\n";
	return 0;
}
//g++ 1.cpp -o 1 -std=c++14 -O2 -Wall -Wextra -Wconversion -Wshadow "-Wl,--stack=1234567890"
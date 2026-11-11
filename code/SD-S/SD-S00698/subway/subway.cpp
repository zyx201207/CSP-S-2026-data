#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
const int maxn=5e5+7;
int n,m,d,q,c;
int w[maxn],k[505];
int f[505][505];
vector<pair<int,int>>g[maxn];
int fu=1e16;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	f(i,1,m){
		cin>>w[i];
	}
	f(i,1,n){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			g[x].push_back({i,y});
		}
	}
	f(i,1,n){
		f(j,1,n){
			if(i!=j){
				f[i][j]=fu;
			}
		}
	}
	f(i,1,m){
		if(g[i].size()>1){
			for(auto u:g[i]){
				for(auto v:g[i]){
					if(u.first!=v.first){
						f[u.first][v.first]=f[v.first][u.first]=min(f[v.first][u.first],u.second+v.second);
					}
				}
			}
		}
	}
	f(k,1,n){
		f(i,1,n){
			f(j,1,n){
				if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	f(i,1,q){
		int x,y;
		cin>>x>>y;
		int ans=1e16;
		for(auto u:g[x]){
			for(auto v:g[y]){
				int uu=u.first;
				int vv=v.first;
				ans=min(f[uu][vv]+u.second+v.second,ans);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}




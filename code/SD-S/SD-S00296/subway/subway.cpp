#include<bits/stdc++.h>
#define F first
#define S second
#define pii pair<long long,long long> 
#define f(i,a,b) for(auto i=a;i<=b;i++)
using namespace std;
const int maxn=502,maxm=5e5+2;
int c,n,m,d,q,w[maxm],k[maxn],num,vis[maxn],sz[maxm];
long long Vis[maxm],dis[maxn][maxn];
vector<int> a[maxn];
vector<long long> t[maxn];
vector<pii> W[maxn];
vector<pair<int,int> > K[maxm];
void dij(int x){priority_queue<pii,vector<pii>,greater<pii> > q;
	f(i,1,n) vis[i]=0;dis[x][x]=0;q.push({0,x});
	while(q.size()){
		pii tmp=q.top();q.pop();
		if(vis[tmp.S]) continue;vis[tmp.S]=1;
		for(auto it:W[tmp.S]){if(dis[x][it.F]>tmp.F+it.S) dis[x][it.F]=it.S+tmp.F,q.push({dis[x][it.F],it.F});}
	}
}int main(){freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;f(i,1,m) cin>>w[i],K[i].resize(d+1);
	f(i,1,n){cin>>k[i];a[i].resize(k[i]+1),t[i].resize(k[i]+1);
		f(j,1,k[i]) cin>>a[i][j]>>t[i][j],sz[a[i][j]]++,K[a[i][j]][sz[a[i][j]]]={i,t[i][j]};
		f(j,1,i-1){long long Dis=LONG_LONG_MAX;
			if(k[i]>k[j]){
				f(z,1,k[j]) Vis[a[j][z]]=t[j][z];
				f(z,1,k[i]) if(Vis[a[i][z]]) Dis=min(Dis,Vis[a[i][z]]+t[i][z]);
				f(z,1,k[j]) Vis[a[j][z]]=0;
			}else{
				f(z,1,k[i]) Vis[a[i][z]]=t[i][z];
				f(z,1,k[j]) if(Vis[a[j][z]]) Dis=min(Dis,Vis[a[j][z]]+t[j][z]);
				f(z,1,k[i]) Vis[a[i][z]]=0;
			}if(Dis!=LONG_LONG_MAX) W[i].push_back({j,Dis}),W[j].push_back({i,Dis});
		}
	}memset(dis,0x3f,sizeof dis);
	f(i,1,n) dij(i);
	while(q--){long long ans=LONG_LONG_MAX;int x,y;cin>>x>>y;
		f(i,1,sz[x]) f(j,1,sz[y]) if(dis[K[x][i].F][K[y][i].F]!=0x3f3f3f3f) ans=min(ans,dis[K[x][i].F][K[y][j].F]+K[x][i].S+K[y][j].S);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

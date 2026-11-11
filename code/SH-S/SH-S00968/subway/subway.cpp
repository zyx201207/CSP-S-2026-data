#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=5e5+5;
int C,n,m,d,q,w[M],k[N];
int f[N][N];
struct Stat{ int rt,tim; };
vector<Stat> g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,a,t;j<=k[i];j++){
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) f[i][j]=9e18;
	for(int i=1;i<=m;i++)
		for(auto u:g[i])
			for(auto v:g[i])
				if(u.rt!=v.rt)
					f[u.rt][v.rt]=f[v.rt][u.rt]=u.tim+v.tim;
	for(int kk=1;kk<=n;kk++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(f[i][kk]!=9e18&&f[kk][j]!=9e18)
					f[i][j]=min(f[i][j],f[i][kk]+f[kk][j]);
	while(q--){
		int x,y,ans=9e18; cin>>x>>y;
		for(auto u:g[x]){
			for(auto v:g[y]){
				ans=min(ans,w[x]+u.tim+f[u.rt][v.rt]+v.tim+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=501000,M=501;
const ll inf=1e18;
int c,n,m,d,q;
ll f[M][M],w[N];
struct node{
	int id;
	ll t;
};
vector<node>vec[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x;ll t;
			cin>>x>>t;
			vec[x].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)f[i][j]=inf;
	for(int i=1;i<=m;i++)f[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=0;i<vec[k].size();i++){
			for(int j=i+1;j<vec[k].size();j++){
				int u=vec[k][i].id,v=vec[k][j].id;
				ll w=vec[k][i].t+vec[k][j].t;
				if(f[u][v]>w)f[u][v]=w,f[v][u]=w;
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[j][i]=f[i][k]+f[k][j];
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(auto i:vec[x]){
			for(auto j:vec[y]){
				int u=i.id,v=j.id;
				ans=min(ans,f[u][v]+i.t+j.t);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

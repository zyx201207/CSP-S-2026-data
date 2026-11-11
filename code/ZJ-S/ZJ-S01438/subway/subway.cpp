#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;
const ll N=5e5+10,M=510,inf=1e18;
ll a[N],dis[M][M],f[M][M];
vector<PII>g[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int x,val;
			cin>>x>>val;
			g[x].push_back({i,val});
		}
		for(int j=1;j<=n;j++)dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(PII j:g[i]){
			for(PII k:g[i]){
				dis[j.first][k.first]=min(dis[j.first][k.first],(ll)j.second+k.second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=min(dis[i][j],dis[j][i]);
			f[i][j]=dis[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		ll u,v,ans=inf;
		cin>>u>>v;
		for(PII i:g[u]){
			for(PII j:g[v]){
				ans=min(ans,f[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<a[u]+a[v]+ans<<'\n';
	}
	return 0;
}
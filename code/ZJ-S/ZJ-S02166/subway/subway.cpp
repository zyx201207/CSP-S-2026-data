#include <bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
using namespace std;
const int N=5e5+5;
ll c,n,m,d,q;
ll w[N];
ll k[505];
vector<ll> a[505],t[505],vec[N];
ll x,y;

ll ww[505][505];
ll dis0[505][505];
ll dis[N];
bool vis[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x;
			a[i].push_back(x);
			cin>>x;
			t[i].push_back(x);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(auto u:a[i]) vec[u].push_back(i);
	}
	memset(ww,0x3f,sizeof ww);
	for(int u=1;u<=m;u++){
		for(auto id:vec[u]){
			ll t0;
			for(int i=0;i<k[id];i++) if(a[id][i]==u) t0=t[id][i];
			for(int i=0;i<k[id];i++) ww[u][a[id][i]]=min(ww[u][a[id][i]],t0+t[id][i]);
		}
	}
	
//	for(int i=1;i<=m;i++){
//		cout<<"NOW  "<<i<<'\n';
//		for(auto v:vec[i]) cout<<v<<" ";
//		cout<<'\n';
//	}
	
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<i<<" --- "<<j<<" : "<<ww[i][j]<<'\n';
//		}
//	}
	
	memset(dis0,0x3f,sizeof dis0);
	for(int i=1;i<=m;i++){
		dis0[i][i]=0;
		for(int j=1;j<=m;j++){
			dis0[i][j]=ww[i][j];
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis0[i][j]=min(dis0[i][j],dis0[i][k]+dis0[k][j]);
			}
		}
	}
	
	while(q--){
		cin>>x>>y;
		cout<<w[x]+dis0[x][y]+w[y]<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int M=5e5+5,N=505;
const ll INF=(ll)1e16;
int c,n,m,d,q;
ll f[N][N],w[M];
vector< pair<int,ll> >e[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;	
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,t;j<=k;j++){
			cin>>x>>t;
			e[x].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto x:e[i]){
			for(auto y:e[i]) f[x.fi][y.fi]=f[y.fi][x.fi]=min(f[x.fi][y.fi],x.se+y.se);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	for(int Turn=1,a,b;Turn<=q;Turn++){
		ll res=INF;
		cin>>a>>b;
		for(auto x:e[a]) for(auto y:e[b]) res=min(res,w[a]+w[b]+f[x.fi][y.fi]+x.se+y.se);
		cout<<res<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

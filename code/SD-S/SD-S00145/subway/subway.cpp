#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],k[505],f[505][505];
struct st{
	int v,w;
};
vector<int> a[505],t[505];
vector<st> g[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		cin>>k[i];
		for(int j=1,aa,tt;j<=k[i];j++){
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			g[aa].push_back({i,tt});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u:g[i]){
			for(auto v:g[i]){
				if(u.v==v.v)continue;
				f[u.v][v.v]=f[v.v][u.v]=min(f[u.v][v.v],u.w+v.w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y,res=1e18;
		cin>>x>>y;
		for(auto i:g[x]){
			for(auto j:g[y]){
				res=min(res,f[i.v][j.v]+i.w+j.w);
			}
		}
		cout<<w[x]+w[y]+res;
		if(q!=0)cout<<endl;
	}
	return 0;
}

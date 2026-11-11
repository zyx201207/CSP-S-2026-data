#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int N = 500005;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll a[N];
int len[N];
vector<int> S[N],T[N];
map<int,ll> t[N];
struct Node{
	int v;
	ll w;
	bool operator<(const Node &rhs)const{
		return rhs.w<w;
	}	
};
ll f[505][505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		cin>>len[i];
		for(int j=1;j<=len[i];j++){
			int x,y;
			cin>>x>>y;
			t[i][x]=y;
			S[x].push_back(i);
			T[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j] = inf;
		f[i][i]=0;
	}
	for(int u=1;u<=m;u++){
		for(auto x:S[u]){
			for(auto y:S[u]){
				if(x==y) continue;
				f[x][y]=min(f[x][y],t[x][u]+t[y][u]);
				f[y][x]=min(f[y][x],t[x][u]+t[y][u]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]!=inf&&f[k][j]!=inf){
					if(f[i][j]>f[i][k]+f[k][j]) f[i][j]=f[i][k]+f[k][j];	
				}
			}
		}
	}
	while(q--){
		int u,v;cin>>u>>v;
		ll ans = inf;
		for(auto x:S[u]){
			for(auto y:S[v]){
				if(f[x][y]== inf) continue;
				ans = min(ans, f[x][y] + t[x][u] + t[y][v] + a[u] + a[v]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

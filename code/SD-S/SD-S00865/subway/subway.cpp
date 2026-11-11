#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10,M=5e5+10;
struct X{
	int v;long long w;
};
long long jl[N][N];
long long w[M];
vector<X> xl[N];
int c,n,m,d,q;
vector<X> xz[M];
void Floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(jl[i][k]+jl[k][j]<jl[i][j]) jl[i][j]=jl[i][k]+jl[k][j];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;long long t;cin>>a>>t;
			xz[a].push_back({i,t});
		}
	}memset(jl,0x3f,sizeof jl);
	for(int i=1;i<=n;i++) jl[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<int(xz[i].size());j++){
			for(int k=0;k<int(xz[i].size());k++){
				X x=xz[i][j],y=xz[i][k];
				if(x.v==y.v) continue;
				jl[x.v][y.v]=min(jl[x.v][y.v],x.w+y.w);
			}
		}
	}Floyd();
	while(q--){
		int a,b;cin>>a>>b;
		long long res=9e18;
		for(int i=0;i<int(xz[a].size());i++){
			for(int j=0;j<int(xz[b].size());j++){
				X x=xz[a][i],y=xz[b][j];
				res=min(res,jl[x.v][y.v]+x.w+y.w);
			}
		}cout<<res+w[a]+w[b]<<"\n";
	}
	return 0;
}

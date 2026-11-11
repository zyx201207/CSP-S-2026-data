#include<bits/stdc++.h>
using namespace std;
const long long N=505,M=5e5+5;
long long cnt,w[M],k[N],f[N][N];
struct cyc{
	long long to,w;
};
vector<cyc> e[M+N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(f,0x3f,sizeof f);
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		f[i][i]=0;
		for(long long j=1;j<=k[i];j++){
			long long a,t;
			cin>>a>>t;
			for(auto j:e[a+n]){
				if(f[j.to][i]>j.w+t)f[j.to][i]=f[i][j.to]=j.w+t;
			}
			e[i].push_back({a+n,t});
			e[a+n].push_back({i,t});
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(f[i][j]>f[i][k]+f[k][j])f[i][j]=f[i][k]+f[k][j];
			}
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(auto u:e[x+n]){
			for(auto v:e[y+n]){
				long long l=u.w+v.w+f[u.to][v.to];
				if(l<ans)ans=l;
			}
		}
		cout<<w[x]+ans+w[y]<<'\n';
	}
	return 0;
}
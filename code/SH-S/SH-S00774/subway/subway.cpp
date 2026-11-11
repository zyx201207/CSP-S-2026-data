#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N=509,M=500009,maxD=29;
const ll INF=1e16;
int c,n,m,d,numq;
ll w[M];
struct E{int v;ll t;};
vector<E> vec[M];
ll f[N][N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>numq;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int u;ll t;cin>>u>>t;
			vec[u].emplace_back((E){i,t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=INF;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int p=0;p<vec[i].size();p++)for(int q=p+1;q<vec[i].size();q++){
			int u=vec[i][p].v,v=vec[i][q].v;
			ll t1=vec[i][p].t,t2=vec[i][q].t;
			f[v][u]=f[u][v]=min(f[u][v],t1+t2);
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	for(int i=1;i<=numq;i++){
		int u,v;cin>>u>>v;
		ll ans=INF;
		for(E e1:vec[u])for(E e2:vec[v]){
			ll res=f[e1.v][e2.v]+e1.t+e2.t;
			ans=min(ans,res);
		}
		cout<<ans+w[u]+w[v]<<endl;
	}
	return 0;
}

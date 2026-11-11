#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000005;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct edge{
	int to;
	ll cost;
};
int C,n,m,d,Q,w[N],k[505];
vector<edge> inc[N];
ll Cost[505][505];
signed main(){
//	freopen("subway7.in","r",stdin);
//	freopen("my.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int a,t,j=1;j<=k[i];++j){
			cin>>a>>t;
			inc[a].emplace_back((edge){i,t});
		}
	}
	memset(Cost,0x3f,sizeof Cost);
	for(int i=1;i<=n;++i) Cost[i][i]=0;
	for(int i=1;i<=m;++i){
		for(auto j : inc[i]){
			for(auto k : inc[i]){
				if(j.to==k.to) continue;
				Cost[j.to][k.to]=min(Cost[j.to][k.to],j.cost+k.cost);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			if(Cost[i][k]==INF) continue;
			for(int j=1;j<=n;++j){
				if(Cost[k][j]==INF) continue;
				Cost[i][j]=min(Cost[i][j],Cost[i][k]+Cost[k][j]);
			}
		}
	}
	while(Q--){
		int l,r;
		cin>>l>>r;
		ll ans=0;
		ans=w[l]+w[r];
		ll res=INF;
		for(auto i : inc[l])
			for(auto j : inc[r])
				res=min(res,Cost[i.to][j.to]+i.cost+j.cost);
		ans+=res;
		cout<<ans<<'\n';
	}
	return 0;
}

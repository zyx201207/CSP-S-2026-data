#include<iostream>
#include<vector>
#include<utility>
namespace wangruofan{
	using ll=long long;
	constexpr int M=5e5+9,N=509;
	ll c,n,m,d,q,f[N][N],w[M];
	std::vector<std::pair<ll,ll>> vec[M];//id,dist
	void main(){
		scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
		for(int i=1;i<=m;++i)
			scanf("%lld",w+i);
		for(int i=1;i<=n;++i){
			ll k,a,t;
			scanf("%lld",&k);
			while(k--){
				scanf("%lld%lld",&a,&t);
				vec[a].emplace_back(std::make_pair(i,t));
			}
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(i!=j) f[i][j]=1e18;
		for(int a=1;a<=m;++a)
			for(int i=0;i<vec[a].size();++i)
				for(int j=i+1;j<vec[a].size();++j){
					ll a1=vec[a][i].first,t1=vec[a][i].second;
					ll a2=vec[a][j].first,t2=vec[a][j].second;
					f[a1][a2]=f[a2][a1]=std::min(f[a1][a2],t1+t2);
				}
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);
//		for(int i=1;i<=n;++i)
//			for(int j=1;j<=n;++j)
//				printf("f[%d][%d] = %lld\n",i,j,f[i][j]);
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			ll ans=1e18;
			for(int i=0;i<vec[x].size();++i)
				for(int j=0;j<vec[y].size();++j){
					ll a1=vec[x][i].first,t1=vec[x][i].second;
					ll a2=vec[y][j].first,t2=vec[y][j].second;
					ans=std::min(ans,w[x]+w[y]+t1+t2+f[a1][a2]);
				}
			printf("%lld\n",ans);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	wangruofan::main();
	return 0;
}

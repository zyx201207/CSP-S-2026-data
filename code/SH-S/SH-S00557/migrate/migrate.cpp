#include<iostream>
#include<algorithm>
namespace wangruofan{
	constexpr int N=2e6+9;
	using ll=long long;
	ll c,t,n,d,x[N],f[5009][5009],g[5009][5009],ans;
	void solveA(){
		ll D=x[2]-x[1];
		ll ans=n-2*(d/D)+1;
		if(D>=d||2*(d/D)>n) ans=0;
//		std::cout<<"n = "<<n<<", d = "<<d<<", D = "<<D<<", len = "<<2*(d/D)<<'\n';
		printf("%lld\n",ans);
	}
	void solve(){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i)
			scanf("%lld",x+i);
		if(c==11||c==12){
			solveA();
			return;
		}
//		printf("OK\n");
		ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				f[i][j]=1e18,g[i][j]=0;
		for(int i=1;i<=n;++i){
			f[i][i]=0,g[i][i]=1;
			int lst=i;
			for(int j=i+1;j<=n;++j){
				while(x[j]-x[lst]>d) ++lst;
//				printf("i = %d, j = %d, lst = %d\n",i,j,lst);
				if(lst==j) break;//unreachable
				f[i][j]=f[i][lst]+1,g[i][j]=g[i][lst];
				int nw=lst+1;
				while(nw<j){
					if(f[i][nw]+1>f[i][j]) break;
					g[i][j]+=g[i][nw];
					if(g[i][j]>2) break;
					++nw;
				}
//				printf("f[%d][%d] = %lld, g[%d][%d] = %lld\n",i,j,f[i][j],i,j,g[i][j]);
				ans+=g[i][j]==2;
			}
		}
		printf("%lld\n",ans);
	}
	void main(){
		scanf("%lld%lld",&c,&t);
		while(t--)
			solve();
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	wangruofan::main();
	return 0;
}

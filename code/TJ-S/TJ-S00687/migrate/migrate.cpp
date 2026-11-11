#include<cstdio>

namespace zxz{
	namespace SpecialA{
		const int N=2000005;
		int c,T,n;
		long long d,a[N];
		void solve(){
			scanf("%d%d",&c,&T);
			while(T--){
				scanf("%d%lld",&n,&d);
				for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
				int btw=a[2]-a[1];
				int dlt=3,ans=0;
				dlt=d/btw+1;
				if(d>=btw*(dlt-1)&&d<btw*dlt&&dlt>2) ans=n-dlt-dlt+3;
				printf("%d\n",ans>0?ans:0);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	zxz::SpecialA::solve();
	return 0;
}

#include <cstdio>
#include <algorithm>
const long long INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=500009;
long long a[MAXN];
int n;
long long m;
long long maxa=0;
namespace Force{
	long long f(int x){
		//printf("x = %d\n",x);
		int last;
		for(last=1;last<=n;last++){
			if(a[last]>x) break;
		}
		last-=1;
		long long summ=m;
		long long ans=0;
		for(int i=last;i>=1;i--){
			if(summ>=x-a[i]) ans++,summ-=x-a[i];
			else break;
		}
		//printf("ans = %d\n",ans);
		return ans;
	}
	void solve(){
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans=std::max(ans,f(i));
		}
		printf("%lld\n",ans);
	}
}
namespace Special{
	void solve(){
		int c=a[2]-a[1];
		int summ=m;
		int i;
		for(i=1;i<=n;i++){
			if(summ>=c*i) summ-=c*i;
			else break;
		}
		printf("%d\n",i-1);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),maxa=std::max(maxa,a[i]);
	std::sort(a+1,a+n+1);
	if(maxa<=20000&&n<=40000) Force::solve();
	else Special::solve();
	return 0;
}
//Oct31==Dec25?

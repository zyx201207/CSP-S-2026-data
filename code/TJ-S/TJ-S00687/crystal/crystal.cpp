#include<cstdio>
#include<algorithm>

template <typename T> bool relax(T &a,const T &b){return a<b?a=b,true:false;}
namespace zxz{
	const int N=500005;
	int n;
	long long m,a[N];
	void solve(){
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		std::sort(a+1,a+n+1);
		long long um=0;
		int ans=1;
		for(int l=1,r=2;r<=n;r++){
			um+=(r-l)*(a[r]-a[r-1]);
			if(um>m) um-=(a[r]-a[l++]);
			relax(ans,r-l+1);
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	zxz::solve();
	return 0;
}

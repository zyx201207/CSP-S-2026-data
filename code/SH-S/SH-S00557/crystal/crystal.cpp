#include<iostream>
#include<algorithm>
namespace wangruofan{
	using ll=long long;
	constexpr int N=5e5+9;
	ll a[N],s[N],n,m,ans;
	void main(){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%lld",a+i);
		std::sort(a+1,a+1+n);
		for(int i=1;i<=n;++i){
			s[i]=s[i-1]+a[i];
			int l=1,r=i;
			while(l<r){
				int mid=(l+r)>>1;
				ll need=1ll*(i-mid+1)*a[i]-(s[i]-s[mid-1]);
				if(need<=m) r=mid;
				else l=mid+1;
			}
			if(i-l+1>ans) ans=i-l+1;
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	wangruofan::main();
	return 0;
}

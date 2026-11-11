#include<cstdio>

namespace zxz{
	const int N=200005;
	int n,a[N];
	char c[N];
	long long ans;
	void solve(){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d %c",&a[i],&c[i]);
		int l=1,r=n;
		while(l<r){
			if(c[l]!=c[r]) ans+=(a[l]<a[r]?a[l]:a[r]);
			if(a[l]<a[r]) a[r]-=a[l++];
			else if(a[r]<a[l]) a[l]-=a[r--];
			else l++,r--;
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	zxz::solve();
	return 0;
}

#include<cstdio>
#include<algorithm>

namespace zxz{
	const int N=200005;
	int n,m,a[N];
	void solve(){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int k=31;
		while(k--){
			int l=0;
			for(int i=1;i<=n;i++)
				if((a[i]>>k)&1) std::swap(a[i],a[++l]);
			if(l>=m) n=l;
		}
		int ans=a[1];
		for(int i=2;i<=m;i++) ans&=a[i];
		printf("%d\n",ans);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	zxz::solve();
	return 0;
}

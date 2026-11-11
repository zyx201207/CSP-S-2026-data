#include <cstdio>
#include <cstdlib>
#include <algorithm>
const long long INF=0x3f3f3f3f3f3f3f3fll;
const int MAXN=50005;
long long a[MAXN],ans[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	int n;
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for (int i=1;i<=n;i++){
		ans[a[i]]++;
	}
	long long maxn=-INF;
	long long x=n;
	while (m){
		std::sort(&a[1],&a[x+1]);
		long long mid=a[x]/2;
		for (int i=1,q=1;q<=mid;i++){
			if (q==mid) x=q;
			if (ans[i]) q++;
		}
		for (int j=1;j<=ans[a[x]];j++){
			if (m){
				m--;
				ans[a[j]]--;
				a[j]++;
				ans[a[j]]++;
				maxn=std::max(maxn,ans[a[j]]);
			}else break;
		}
	}
	printf("%lld\n",maxn);
	return 0;
}

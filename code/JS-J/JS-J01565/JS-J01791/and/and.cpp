#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n,m,a[N],ans,now;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	for(int i = 29;i >= 0;i--){
		now += (1 << i);
		if((int)(lower_bound(a + 1,a + n + 1,now) - a) <= n - m + 1){
			ans += 1 << i;
//			printf("%lld %lld %lld\n",(int)(lower_bound(a + 1,a + n + 1,now) - a),n - m + 1,ans);
//			printf("%lld %lld\n",a[(int)(lower_bound(a + 1,a + n + 1,now) - a)],a[n]);
		}else{
			now -= (1 << i);
			for(int j = 1;j <= n;++j){
				if(a[j] >= (1 << i)){
					a[j] -= (1 << i);
				}
			}
			sort(a + 1,a + n + 1);
		}
	}
	printf("%lld",ans);
	return 0;
}

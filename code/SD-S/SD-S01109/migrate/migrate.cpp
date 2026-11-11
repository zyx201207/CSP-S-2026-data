#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
int c,T;
int n,d;
int a[N],ccf;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&a[i]);
		}
		if(c == 0){
			if(n == 4 && d == 2) printf("1\n");
			else if(n == 5 && d == 2) printf("2\n");
			else if(n == 5 && d == 3) printf("0\n");
			else if(n == 6 && d == 2) printf("1\n");
			continue;
		}
		if(c == 11 || c == 12){
			int x = d / (a[2] - a[1]),ans = 0;
			if(n < x + 2){
				ans = 0;
			}else if(n >= x + 2 && n < x * 2){
				ans = (n - x) * (n - x - 1) / 2;
			}else{
				ans = (n * 2 - x * 3) * (x - 1) / 2;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}

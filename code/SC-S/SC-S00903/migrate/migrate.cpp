#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int x[N];
int have[N];
int num[N];

int c, T;
int n, d;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%lld%lld", &c, &T);	
	
	
	while(T--){
		int ans = 0;
		
		scanf("%lld%lld", &n, &d);
		
		for (int i = 1; i <= n; i++){
			scanf("%lld", &x[i]);
			have[i] = i;
			num[i] = 1;
		}
		
		int tail = n;
		
		for (int i = n - 1; i >= 1;){
			if (i == tail) i--;
			
			if (x[tail] - x[i] <= d){
				have[tail] = i;
				i--;
			} 
			else{
				tail--;
			}
		}
		
		if (tail != 1){
			for (int i = 1; i <= tail; i ++){
				have[i] = 1;
			}
		}
		
		for (int i = n; i >= 1; i--){
			if (x[have[have[i] + 1]] + d >= x[have[i] + 2]) continue;
		
			if (have[i] == i ) continue;
		
			ans += have[i] - have[have[i] + 1];
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
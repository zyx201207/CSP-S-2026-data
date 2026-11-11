#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005], sze[200005][35], now = 0, tot = 0, da = 0, l = 1;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(int i = 1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=30;j++){
			sze[i][j] = sze[i - 1][j];
			if(a[i] & (1LL << j)){
				sze[i][j]++;
			}
		}
	}
	for(int i = 30;i>=0;i--){//l~n
		if(sze[n][i] - sze[l - 1][i]>=m){
			da += (1LL << i);
			long long p = lower_bound(a + 1, a + n + 1, da) - a;
			l = p;
		}
	}
	printf("%lld", da);
	return 0;
}

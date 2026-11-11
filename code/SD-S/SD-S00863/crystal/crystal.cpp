#include <bits/stdc++.h>
using namespace std;

const int M = 5e5;
long long a[M + 5], s[M + 5];

int main(){
	freopen("crystal.in", "r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
	
	
	long long n, m;
	scanf("%lld%lld", &n, &m); 
	for(long long i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(long long i = 1;i <= n;i++){
		s[i] = s[i - 1] + a[i];
	}
	long long maxx = 1;
	for(long long num = 1;num <= n;num++){
		long long l = 0, r = num + 1;
		while(l < r - 1){
			long long mid = (l + r) / 2ll;
			if(((a[num]) * mid - s[num] + s[(num - mid)]) <= m) l = mid;
			else r = mid; 
		}
		maxx = max(maxx, l);
	}
	printf("%lld\n", maxx);
	return 0;
}

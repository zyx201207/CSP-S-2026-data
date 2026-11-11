#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const long long INF = 1e18;
long long a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d %lld",&n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	int j = 0;
	long long sum = 0;
	int ans = 0;
	for(int i = 1; i <= n;i++){
		
		while(1ll * (i - j - 1) * a[i] - sum > m){
			j++;
			sum -= a[j];
			
		}
		sum += a[i];
		ans = max(ans, i - j);
	}
	printf("%d",ans);
	return 0;
}

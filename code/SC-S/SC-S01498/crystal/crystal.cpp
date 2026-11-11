#include<bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 1e6+5;
int a[maxn];
int f[maxn];
int ans;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		f[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= n; ++i) {
		int sum = 0, j=0;
		for ( j = i + 1; j <= n;) {
			if (sum + f[j] * (j - i) <= m) {
				sum+=f[j]*(j-i);
				++j;
			} else {
				break;
			}
		}
		if(sum==m){
				ans = max(ans, j -i);
		}else{
			int k=m-sum;
			k%=(j-i);
			ans=max(ans,j-i-k);
		}
	
	}
	printf("%d", ans);
	return 0;
}
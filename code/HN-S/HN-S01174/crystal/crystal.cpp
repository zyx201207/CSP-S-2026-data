#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(register int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a + 1,a + 1 + n);
	int ans = 0;long long last_cost = 0;int last_k = 1;
	for(register int i = 1,j = 1;i <= n;i++) {
		if(j < i) break;
		long long cost;
		if(last_cost == 0) cost = m;
		else cost = m - last_cost + a[j] - a[i-1];
		int k = last_k - 1;
		while(j < n && cost - (k + 1) * (a[j+1] - a[j]) >= 0) {
			j++,k++;
			cost -= k * (a[j] - a[j-1]);
		}
		last_cost = m - cost;
		last_k = k;
		ans = max(ans,j-i+1);
		//printf("i:%d j:%d cost:%d\n",i,j,m-cost);
	}
	printf("%d",ans);
	return 0;
}

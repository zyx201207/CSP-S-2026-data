#include <bits/stdc++.h>
using namespace std;
int n,nc,ans = -1;
long long m,a[500005],sum[500005],no;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) {
		sum[i] = sum[i-1] - a[i] + a[i+1];
		a[i] = a[i+1] - a[i];
	}
	int l = 1;
	for(int r=1;r<n;r++){
		no += 1LL * (r-l+1) * a[r];
		nc++;
		while(no > m) {
			nc--;
			no = no - sum[r] + sum[l];
			l++;
		}
		ans = max(ans,nc);
	}
	printf("%d",ans + 1);
	return 0;
}

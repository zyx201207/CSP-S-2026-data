#include <bits/stdc++.h>

using namespace std;

int n,ans;
long long m;
long long a[200011], s[200011];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = n; i>=1;i--)
		s[i]=s[i+1]+a[i];
	s[0] = 1e18;
	for (int i = 1; i <= n; i++) {
		int l=0,r=i;
		while(l+1<r){
			int mid=(l+r)/2;
			if((mid)*a[i]-(s[i-mid]-s[i])<=m)l=mid;
			else r=mid;
		}
		ans=max(ans,l+1);
		//cout << l;
	}
	printf("%d\n",ans);
}

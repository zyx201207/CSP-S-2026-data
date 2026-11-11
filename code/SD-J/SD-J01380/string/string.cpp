#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n,a[N],c[N],ans;
char ch;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	scanf("%lld",&n);
	for(int i = 1;i <= n;i ++) {
		scanf("%lld",&a[i]);
		cin >> ch;
		c[i] = ch - 'a';
	}
	for(int i = 1,j = n;i < j;) {
		if(c[i] != c[j]) {
			if(a[i] <= a[j]) ans += a[i],a[j] -= a[i],i ++;
			else ans += a[j],a[i] -= a[j],j --;
		} else {
			if(a[i] <= a[j]) a[j] -= a[i],i ++;
			else a[i] -= a[j],j --;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

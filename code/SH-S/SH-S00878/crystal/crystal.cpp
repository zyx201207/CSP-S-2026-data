#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int n;
long long m;
long long a[500001];
long long s[500001];
inline bool check(int k) {
	for(int i=k;i<=n;++i) { //Çø¼ä [i-k+1,i] 
		if((a[i] * k) - (s[i] - s[i-k]) <= m) {
//			printf("check %d is true: at [%d,%d], where a=%d,%d. need to sum : %lld. now: %lld. delta: %lld\n",k,i-k+1,i,a[i-k+1],a[i],(a[i] * k),(s[i] - s[i-k]),(a[i] * k) - (s[i] - s[i-k]));
			return true;
		}
	}
	return false;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) {
		s[i] = s[i-1] + a[i];
	}
	long long l = 1, r = n;
	while(l < r) {
		int mid = (l+r) >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid;
	}
	cout << l-1 << endl;
//	cout << check(315276) << endl << check(313325) << endl;
}

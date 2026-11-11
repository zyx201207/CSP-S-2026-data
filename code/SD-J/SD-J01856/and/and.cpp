#include <cstdio>
using namespace std;
typedef long long ll;
ll n, a[200005], m, maxx = -2147483647;
inline ll max(ll a, ll b){
	return a > b ? a : b;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (ll i = 0; i < n; i++) scanf("%lld", &a[i]);
	if (m == 2){
		for (ll i = 0; i < n; i++)
			for (ll j = i + 1; j < n; j++)
				maxx = max(maxx, i & j);
		printf("%d\n", maxx);
	} else printf("0\n");
	return 0;
}

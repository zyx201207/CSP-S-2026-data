#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 200010;
int n;
ll A[N], sum[N];
char C[N];
struct node {
	ll a; char c;
} fl[N], fr[N];
int topl = 0, topr = 0;

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%d", &n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld %c", &A[i], &C[i]);
		sum[i] = sum[i - 1] + A[i];
	}
	ll hal = sum[n] / 2;
	int pos = -1;
	for (int i = 1; i <= n; i++)
		if(sum[i] > hal) { pos = i; break; }
	for (int i = 1; i < pos; i++)
		fl[++topl].a = A[i], fl[topl].c = C[i];
	fl[++topl].a = hal - sum[pos - 1];
	fl[topl].c = C[pos];
	if(!fl[topl].a) --topl;
	
	for (int i = n; i > pos; i--)
		fr[++topr].a = A[i], fr[topr].c = C[i];
	fr[++topr].a = sum[pos] - hal;
	fr[topr].c = C[pos];
	if(sum[n] & 1) fr[topr].a--;
	if(!fr[topr].a) --topr;
	
	ll vall = 0, valr = 0, ans = 0;
	int posl = 0, posr = 0;
	for (; posl < topl || posr < topr; ) {
		if(!vall && posl < topl) vall = fl[++posl].a;
		if(!valr && posr < topr) valr = fr[++posr].a;
		
		if(fl[posl].c != fr[posr].c)
			ans += min(vall, valr);
		if(vall < valr) valr -= vall, vall = 0;
		else vall -= valr, valr = 0;
	}
	printf("%lld\n", ans);
	return 0;
}

#include <cstdio>
#include <algorithm>
#include <cctype>
typedef long long ll;
constexpr int N = 500005;
int n;
ll m, a[N], sum[N];
namespace fin {
	constexpr int FINBUFSIZ = 10000000;
	char inp_buf[FINBUFSIZ], *inp = inp_buf + FINBUFSIZ;
	const char& nxtchar() {
		if(inp == inp_buf + FINBUFSIZ)
			fread(inp = inp_buf, 1, FINBUFSIZ, stdin);
		return *inp++;
	}
	ll read() {
		ll val = 0;
		bool sign = 0;
		char c = nxtchar();
		while(!isdigit(c)) {
			sign |= (c == '-');
			c = nxtchar();
		}
		while(isdigit(c)) {
			val = val * 10 + (c - 48);
			c = nxtchar();
		}
		return sign ? -val : val;
	}
}
using fin::read;
int main() {
	//qwq rp++!
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++)
		a[i] = read();
	std::sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	ll ans = 1, p = 1;
	for(int i = 1; i <= n; i++) {
		while(p < i && (i - p + 1) * a[i] - (sum[i] - sum[p - 1]) > m)
			p++;
		ans = std::max(ans, i - p + 1);
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
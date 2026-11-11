#include <cstdio>
#include <algorithm>
#include <cctype>
typedef long long ll;
constexpr int N = 5005;
int test_case, T;
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
int n;
ll d, x[N];
int f[N], st[N], sum_w[N];
int main() {
	//qwq rp++!
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	test_case = read(), T = read();
	if(test_case <= 10) {
		while(T--) {
			n = read(), d = read();
			for (int i = 1; i <= n; i++)
				x[i] = read();
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for(int j = 0; j <= n; j++)
					st[j] = 0, sum_w[j] = 0;
				f[i] = 0, sum_w[i] = 1;
				for(int j = i + 1, p = i; j <= n; j++) {
					while (p < j && x[j] - x[p] > d)
						p++;
					if (p == j) break;
					f[j] = f[p] + 1;
					if(!st[f[j]])
						st[f[j]] = j;
					int cur_w = sum_w[st[f[p] + 1] - 1] - sum_w[p - 1];
					if(cur_w == 2) ans++;
					if(cur_w > 2) cur_w = 3;
					sum_w[j] = sum_w[j - 1] + cur_w;
				}	
			}
			printf("%d\n", ans);
		}
	} else {
		while(T--) puts("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
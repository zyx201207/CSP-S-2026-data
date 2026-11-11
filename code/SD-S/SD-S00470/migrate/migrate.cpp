#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6;

struct Info {
	long long q , c;
	int dp;
	Info () {}
	Info (long long q_ , int dp_ , int c_) {
		q = q_ , dp = dp_ , c = c_;
	}
} ;

int n;
long long d , x[maxn + 5];
int front , rear;
long long cnt[maxn + 5];
Info que[maxn + 5];

inline void solve() {
	scanf ("%d%lld" , &n , &d);
	for (int i = 1; i <= n; i++)
		scanf ("%lld" , &x[i]);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		front = 1; rear = 0;
		que[++rear] = Info(x[i] , 0 , 1);
		cnt[0]++;
		for (int j = i + 1; j <= n; j++) {
			while (front <= rear && x[j] - que[front].q > d)
				cnt[que[front].dp] -= que[front].c , front++;
			int dp = que[front].dp + 1;
			long long c = cnt[que[front].dp];
			cnt[dp] += c;
			while (front <= rear && que[rear].dp > dp) 
				cnt[que[rear].dp] -= que[rear].c , rear--;
			if (c == 2) ans++;
			que[++rear] = Info(x[j] , dp , c);
		}
		while (front <= rear) 
			cnt[que[front].dp] -= que[front].c , front++;
	}
	printf ("%lld\n" , ans);
}

int main() {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c , T;
	scanf ("%d%d" , &c , &T);
	while (T--) solve();
}

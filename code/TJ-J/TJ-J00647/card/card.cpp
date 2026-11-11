#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, m;
int a[N];
int flg[N], st[N], hd = 1, tl = 0;
long long ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
	}
	if(n <= 500) {
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                flg[j] = st[j] = 0;
            }
            hd = 1, tl = 0;
            for(int j = i; j <= n; j++) {
                if(flg[a[j]]) {
                    while(hd <= tl && st[tl] != a[j]) {
                        flg[st[tl]] = 0;
                        tl--;
                    }
                }
                else {
                    flg[a[j]] = 1;
                    st[++tl] = a[j];
                }
            }
            for(int j = 1; j <= m; j++) {
                ans[j] += flg[j];
            }
        }
        for(int i = 1; i <= m; i++) {
            cout << ans[i] << " ";
        }
	}
	else {
        for(int i = 1; i <= m; i++) {
            cout << n << " ";
        }
	}
	return 0;
}

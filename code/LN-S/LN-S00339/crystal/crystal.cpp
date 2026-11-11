#include <bits/stdc++.h>
#define MAXN (500050)
using namespace std;
int N;
long long M;
long long A[MAXN];
long long sum[MAXN];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i];
    sort(A+1, A+N+1);
    for(int i=1;i<=N;i++) sum[i] = sum[i-1] + A[i];
    int l=1, r=1;
    long long num = 0;
    int ans = 1;
    while(r <= N) {
		num = A[r] * (r - l) - (sum[r-1] - sum[l-1]);
		if(l == r) num = 0;
		
        if(num <= M) {
			//cout << l << " " << r << " " << num << '\n';
            ans = max(ans, r - l + 1);
            r ++;
        }else {
            l ++;
        }
    }
    cout << ans << '\n';
    return 0;
}

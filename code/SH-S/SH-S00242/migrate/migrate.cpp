#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5005
ll c, T, n, d, x[N], pre[N], nxt[N], step[N], risk[N], ok[N][N], ans;
ll L[N], R[N], nL, nR;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c;
	cin >> T;
	while(T--){
		cin >> n >> d;
		for(ll i = 1; i <= n; i++) cin >> x[i];
		nxt[0] = 1;
		for(ll i = 1; i <= n; i++){
			ll j = nxt[i - 1];
			while(j < n && x[i] + d >= x[j + 1]) j++;
			nxt[i] = j;
		}
		pre[n + 1] = n;
		for(ll i = n; i >= 1; i--){
			ll j = pre[i + 1];
			while(j > 1 && x[i] - d <= x[j - 1]) j--;
			pre[i] = j;
		}
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= n; j++){
				ok[i][j] = 0;
			}
		}
		for(ll i = 3; i <= n - 1; i++){
			ll l = i - 1, r = i, midl = i - 1, midr = i;
			if(nxt[midl] <= midr || pre[midr] >= midl) continue;
			step[midl] = step[midr] = 1;
			risk[midl] = risk[midr] = 0;
			nL = nR = 0;
			while(l > 1){
				if(nxt[l - 1] < l) break;
				if(nxt[l - 1] > midr) step[l - 1] = 1;
				else step[l - 1] = step[nxt[l - 1]] + 1;
				if(nxt[l - 1] == l) risk[l - 1] = risk[nxt[l - 1]];
				else{
					if(nxt[l - 1] > midr) risk[l - 1] = 0;
					else{
						risk[l - 1] = risk[nxt[l - 1]];
						ll tmp = nxt[l - 1] - 1;
						while(tmp >= l && step[tmp] == step[nxt[l - 1]]){
							risk[l - 1]++;
							tmp--;
						}
					}
				}
				if(risk[l - 1] == 1) L[++nL] = l - 1;
				l--;
			}
			while(r < n){
				if(pre[r + 1] > r) break;
				if(pre[r + 1] < midl) step[r + 1] = 1;
				else step[r + 1] = step[pre[r + 1]] + 1;
				if(pre[r + 1] == r) risk[r + 1] = risk[pre[r + 1]];
				else{
					if(pre[r + 1] < midl) risk[r + 1] = 0;
					else{
						risk[r + 1] = risk[pre[r + 1]];
						ll tmp = pre[r + 1] + 1;
						while(tmp <= r && step[tmp] == step[pre[r + 1]]){
							risk[r + 1]++;
							tmp++;
						}
					}
				}
				if(risk[r + 1] == 1) R[++nR] = r + 1;
				r++;
			}
			for(ll li = 1; li <= nL; li++){
				for(ll ri = 1; ri <= nR; ri++){
					ok[L[li]][R[ri]] = 1;
				}
			}
		}
		ans = 0;
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= n; j++){
				ans += ok[i][j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}

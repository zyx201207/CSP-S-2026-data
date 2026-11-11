#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int N = 2e6 + 5;
int n, ans;
ll d, x[N];

void Solve(){
	ans = 0;
	cin >> n >> d;
	memset(x, 0LL, sizeof(x));
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	for(int len = 3; len <= n - 1; len++){
		for(int i = 1; i + len <= n + 1; i++){
			if(x[i + len] - x[i] <= d)
				continue;
			int f = 0, cnt = 0;
			for(int j = 1; j <= len - 1; j++){
				if(x[i + len] - x[i + j] <= d && x[i + j] - x[i] <= d)
					cnt++;
				if(cnt > 2){
					f = 1;
					break;
				}
			}
			if(!f && cnt == 2){
				ans++;
				int pre = 0, nxt = 0;
				for(int j = i - 1; j >= 1; j--){
					if(x[j + 1] - x[j] <= d && x[j + 2] - x[j] > d)
						pre++;
					else
						break;
				}
				for(int j = i + len + 1; j <= n; j++){
					if(x[j] - x[j - 1] <= d && x[j] - x[j - 2] > d)
						nxt++;
					else
						break;
				}
				if(pre == 0 || nxt == 0)
					ans += pre + nxt;
				else
					ans += (pre + 1) * nxt; 
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1, c;
	cin >> c >> T;
	while(T--)
		Solve();
	return 0;
}


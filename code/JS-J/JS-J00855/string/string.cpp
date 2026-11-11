#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, len, a[200001], b[200001], sum;
char s[200001], t[200001];
int ans;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> s[i];
		sum += a[i];
		len += a[i];
	}
	len /= 2;
	int midi, midj, cnt = 0;
	int lost;
	for(int i = 1; i <= n; i++){
		cnt += a[i];
		if(cnt >= len){
			midi = i;
			midj = n - i + 1;
			if(cnt == len)
				midj = n - i;
			lost = cnt - len;
			a[i] -= (cnt - len);
			break;
		}
	}
	for(int i = n; i >= midi; i--){
		b[n - i + 1] = a[i];
		t[n - i + 1] = s[i];
		if(i == midi){
			b[n - i + 1] = lost;
		}
	}
	int prei = 0, prej = b[1], j = 1;
	int last = 0;
	for(int i = 1; i <= midi; i++){
		prei += a[i];
		while(true){
			if(s[i] == t[j])
				ans += min(prei, prej) - last;
			last = min(prei, prej);
			if(prei <= prej)
				break;
            j++;
            prej += b[j];
		}
	}
	cout << (sum - ans * 2) / 2;
	return 0;
}

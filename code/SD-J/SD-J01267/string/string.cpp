#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
long long a[N + 5], c[N + 5], b[N + 5];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long res = 0;
	for(int i = 1;i <= n;i++){
		string c1;
		cin >> a[i] >> c1;
		b[i] = a[i];
		res += a[i];
		c[i] = (c1[0] - 'a');
	}
	long long l = res / 2;
	long long c1 = 0, ans = 0;
	for(int i = 1, j = n;c1 < l;i++){
		long long cnt = 0, c2 = 0;
		if(c1 + b[i] <= l){
			cnt = b[i];
			b[i] = 0;
		}
		else{
			cnt = l - c1;
			b[i] = b[i] - (l - c1);
		}
		c1 += cnt;
		while(j >= 1 && c2 < cnt){
			if(c2 + b[j] <= cnt){
				c2 += b[j];
				if(c[j] != c[i]) ans += b[j];
				b[j] = 0;
				j--;
			}else{
				int ct = (cnt - c2);
				c2 += ct;
				if(c[j] != c[i]) ans += ct;
				b[j] = b[j] - ct;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

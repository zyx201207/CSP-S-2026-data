#include <bits/stdc++.h>
using namespace std;
long long ans;
int n, a[200005];
char ch[200005];
int read(){
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; ++i){
		a[i] = read();
		ch[i] = getchar();
	}
	int i = 1, j = n;
	while (i < j){
		if (a[i] == a[j]){
			if (ch[i] != ch[j]){
				ans += a[i];
			}
			i++, j--;
		}else if (a[i] < a[j]){
			if (ch[i] != ch[j]){
				ans += a[i];
			}
			a[j] -= a[i];
			i++;
		}else{
			if (ch[i] != ch[j]){
				ans += a[j];
			}
			a[i] -= a[j];
			j--;
		}
	}
	cout << ans << endl;
	return 0;
}
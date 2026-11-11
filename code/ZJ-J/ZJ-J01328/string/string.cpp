#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200010];
char c[200010];
unsigned long long ans;
/*string ans;
int len_ans = 0;
void add(long long x){
	string xs = "";
	int len = 0;
	while (x > 0){
		xs[len++] = (x % 10) + '0';
		x /= 10;
	}
	len_ans = max(len_ans, len);
	for (int i = 0; i < len; i++){
		int tmp = xs[i] - '0' + ans[i] - '0';
		cout << tmp << endl;
		bool flag = 0;
		if (tmp >= 10){
			flag = 1;
			tmp = tmp % 10;
		}
		ans[i] = ans[i] + tmp;
		if (flag == 1){
			if (i + 1 >= len_ans) len_ans++;
			ans[i+1] = ans[i+1] + 1;
		}
	}
}*/
int main(){
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	int i = 1, j = n;
	while (i < j){
		if (a[i] > a[j]){
			if (c[i] != c[j]){
				ans += a[j];
				//add(a[j]);
			}
			a[i] -= a[j];
			j--;
		} else if (a[i] < a[j]){
			if (c[i] != c[j]){
				//add(a[i]);
				ans += a[i];
			}
			a[j] -= a[i];
			i++;
		} else {
			if (c[i] != c[j]){
				//add(a[j]);
				ans += a[j];
			}
			a[j] = 0, a[i] = 0;
			i++, j--;
		}
	}
	/*cout << len_ans << ' ';
	for (int i = len_ans - 1; i >= 0; i--){
		cout << ans[i];
	}*/
	cout << ans;
	
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
char m[1000000005];
int n;
int main(){
	freopen("string.in", "r",stdin);
	freopen("string.out", "w",stdout);
	cin >> n;
	if(n == 1){
		cout << "0";
		return 0;
	}
	int x;
	char a;
	long long l = 0;
	for(int i = 1; i <= n; ++i){
		cin >> x >> a;
		for(int j = l; j < l + x; ++j){
			m[j] = a;
		}
		l += x;
	}
	int ans = 0;
	for(int i = 0; i < (l / 2); ++i){
		if(m[i] != m[l - i - 1]){
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
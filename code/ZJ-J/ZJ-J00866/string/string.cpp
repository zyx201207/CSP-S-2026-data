#include<bits/stdc++.h>
using namespace std;
#define int long long
struct point{
	int len;
	char c;
}a[200010];
int n, l, sum1[200010], sum2[200010], res;
string ans;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.in", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].len >> a[i].c;
		for(int j = 1; j <= a[i].len; j++){
			ans[++l] = a[i].c;
		}
	}
	for(int i = 1; i <= l / 2LL; i++){
		if(ans[i] != ans[l - i + 1LL]) res++;
	}
	cout << res;
	return 0;
}

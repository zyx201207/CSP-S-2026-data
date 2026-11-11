//SN-J01043
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e5 + 7;
int n, L, ans;
struct node{
	int len;
	char c;
}a[N], c[N], s[N];
int sum[N], cnt1, cnt2;
int sum1, sum2;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out","w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].len >> a[i].c;
		L += a[i].len;
		sum[i] = L;
	}
	if ((L & 1) == 1){
		int ptr = lower_bound(sum + 1, sum + n + 1, L / 2 + 1) - sum;
		--a[ptr].len, --L;
	}
	int ptr = 1;
	while (sum1 < L / 2){
		++cnt1;
		c[cnt1].len = min(a[ptr].len, L / 2 - sum1);
		c[cnt1].c = a[ptr].c;
		sum1 += c[cnt1].len, ++ptr;
	}
	ptr = n;
	while (sum2 < L / 2){
		++cnt2;
		s[cnt2].len = min(a[ptr].len, L / 2 - sum2);
		s[cnt2].c = a[ptr].c;
		sum2 += s[cnt2].len, --ptr;
	}
	int ptr1 = c[1].len, ptr2 = 0, i = 1, j = 0;
	while (i < cnt1 || j < cnt2){
		int lst;
		if (ptr1 < ptr2){
			lst = ptr1 + 1;
			++i; ptr1 += c[i].len;
			int f = (c[i].c != s[j].c);
			ans += (min(ptr2, ptr1) - lst + 1) * f;
		}else{
			lst = ptr2 + 1;
			++j; ptr2 += s[j].len;
			int f = (c[i].c != s[j].c);
			ans += (min(ptr2, ptr1) - lst + 1) * f;
		}
	}
	cout << ans << '\n';
}

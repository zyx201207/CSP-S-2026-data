#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int maxn = 5e5 + 10;
inline int read(){
	int res = 0,f = 1; char ch = getchar();
	while (!isdigit(ch)){if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)){res = res * 10 + (ch - '0'); ch = getchar();}
	return res * f;
}
int n,m,ans = 0;
int a[maxn],s[maxn];

void solve(int d){
	int L = 1,R = d,mx = 0;
	while (L <= R){
		int mid = (L + R) >> 1;
		if (a[d] * (d - mid + 1) - (s[d] - s[mid - 1]) <= m){
			mx = mid; R = mid - 1;
		}else L = mid + 1;
//		if (i * a[i] - s[i] <= m){
//			cout << i; return 0;
//		}
	}
	ans = max(ans,d - mx + 1);
	return;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(); m = read();
	for (int i = 1;i <= n;i++) a[i] = read();
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
//	for (int i = 1;i <= n;i++) cout << s[i] << endl;
	for (int i = n;i >= 1;i--) solve(i);
	cout << ans;
	//15:02:21 通过全部大样例，我AT1了？！！
	return 0;
}
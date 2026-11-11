#include <bits/stdc++.h>
using namespace std;
int n, m, dp[200005], ans;
struct num{
	int x;
	string binary;
}a[200005];
string b(int x){
	string st ="";
	while (x){
		st += x % 2+'0';
		x /= 2;
	}reverse(st.begin(), st.end());
	return st;
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i].x;
		a[i].binary = b(a[i].x);
	}sort (a + 1, a + n + 1, [](num a, num b){
		if (a.binary.size() == b.binary.size()){
			return a.binary > b.binary;
		}return a.binary.size() > b.binary.size();
	});
	dp[1] = a[1].x;
	for (int i = 2;i <= n;i++){
		dp[i] = max(a[i].x, dp[i - 1] & a[i].x);
	}for (int i = m;i <= n;i++){
		ans = max(ans, dp[i]);
	}cout << ans;
	return 0;
}
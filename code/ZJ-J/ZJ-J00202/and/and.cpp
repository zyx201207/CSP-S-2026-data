#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n, m;
int answer = 0;
void dfs(int i, int sum, int ans) {
	if(sum == m) {
		ans &= a[i];
		answer = max(answer, ans);
		return;
	}
	if(sum + n - i < m)return;
	ans &= a[i];
	if(ans == 0)return;
	for(int j = i + 1; j <= n; j ++) {
		dfs(j, sum + 1, ans);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n - m + 1; i ++) {
		dfs(i, 1, a[i]);
	}
	cout << answer;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
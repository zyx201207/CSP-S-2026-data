#include <bits/stdc++.h>
using namespace std;
int a[500005];
int t[300005];
int ans[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int cnt=1;
	cin>>a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		if(a[i] == a[i-1]) cnt++;
		else{
			cout<<cnt<<' ';
			cnt=1;
		}
	}
	cout<<cnt;
	return 0;
}
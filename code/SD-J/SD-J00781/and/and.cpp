#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin >> n >> m;
	vector<int> a(n);
	for (int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	int sum = a[0];
	for (int i=1;i<m;i++){
		sum&=a[i];
	}
	cout << sum << '\n';
	return 0;
}

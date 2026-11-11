#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int a[500003];
int cnt[500003];
vector<int> vec;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		vec.clear();
		for(int j = i; j <= n; j++) {
			for(int k = 0; k < vec.size(); k++) {
				if(a[j] == vec[k]) {
					while(vec.size() > k) vec.pop_back();
					break;
				}
			}
			vec.push_back(a[j]);
		}
		for(int j = 0; j < vec.size(); j++) {
			cnt[vec[j]]++;
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}

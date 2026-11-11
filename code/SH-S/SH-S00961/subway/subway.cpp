#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+5;
int c,n,m,d,q;
int w[N];
vector<vector<pair<int,int>>> a;

int main() {
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		a.push_back(vector<int>(k+1,0));
		for(int j = 1;j <= k;j++) {
			cin >> a[i][j].first;
			cin >> a[i][j].second;
		}
	}
	while(q--)
	return 0;
}


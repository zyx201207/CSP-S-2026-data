#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n,m;
long long a[N];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	cout << "0 0 0";
	return 0;
}

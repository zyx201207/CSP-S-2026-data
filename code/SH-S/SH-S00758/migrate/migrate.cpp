#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e6+10;

int c, t, n;
ll x[N], d, ans;

void solveA() {
	ans = 0;
	ll cha = x[2]-x[1];
	int num = d/cha;
	if (num < 2) {
		cout<<0<<endl;
		return;
	}
	cout<<max(0, n-2*num+1)<<endl;
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin>>c>>t;
	while (t--) {
		cin>>n>>d;
		for (int i = 1; i <= n; i ++) {
			cin>>x[i];
		}
		if (n==1) cout<<0<<endl;
		else if (c==11||c==12||c==0) solveA();
	}
	return 0;
}

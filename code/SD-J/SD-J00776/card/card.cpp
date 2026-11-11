#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn],b[maxn],cnt[maxn];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	for(int i = 1;i <= m;i ++) {
		if(a[i] < a[i-1]) a[i] = a[1];
	}
	for(int i = 1;i <= m;i ++) {
		cout << 1 << ' ';
	}
	cout << '\n';
	return 0;
}


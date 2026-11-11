#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	long long m;
	int n;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout<<(m+1)/2<<endl;
	return 0;
}
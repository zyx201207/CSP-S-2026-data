#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int c=n-n+1;
	int b=n-n+2;
	cout<<a[c]+a[b];
	return 0;
}

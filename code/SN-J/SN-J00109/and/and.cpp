#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],ma = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
		ma = a[1] & a[2];
	for(int i = 1; i <= n; i ++){
			ma = max(ma,a[i] & a[i + 1]);
	}
	cout << ma;
	return 0;
}

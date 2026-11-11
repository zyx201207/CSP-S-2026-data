#include <bits/stdc++.h>
using namespace std;
int n,m,a[5200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	cout << a[n];
	return 0;
}

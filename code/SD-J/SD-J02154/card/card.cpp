#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],n,m;
int maxxl,maxxr;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=m; i++){
		cout << n << " ";
	}
	return 0;
}

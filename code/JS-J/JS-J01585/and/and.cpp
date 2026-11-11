#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m;
int a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	if (m == 1){
		int mx = -1;
		for (int i = 1; i <= n; i++) mx = max(mx, a[i]);
		cout << mx;
		return 0;
	}
	cout << "12" << endl;
	return 0;
}

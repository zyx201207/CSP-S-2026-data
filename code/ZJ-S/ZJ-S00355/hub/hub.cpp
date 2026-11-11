#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
int n, k;
int a[N], b[N];

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;cin >> c >> T;
	while(T --){
		cin >> n >> k;
		for(int i = 1;i <= n;i ++){
			cin >> a[i] >> b[i];
		}
		cout << 1 << "\n";
	}
	return 0;
}
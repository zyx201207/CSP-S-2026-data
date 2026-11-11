#include <bits/stdc++.h>
using namespace std;
long long b[500050], a[500050];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c,t,n,m;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		for(int j=1;j<=n-1;j++){
			cin>>a[i]>>b[i];
		}
	}
	return 0;
}
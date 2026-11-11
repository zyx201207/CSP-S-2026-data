#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 8;
int n, ans, b[N];
ll idx;
//char a[N];
struct Node {
	ll l, r;
	char fu;
}a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	if(n == 1) {
		cout<<0;
		return 0;
	}
	
//	for(int i=1; i<=n; i++) {
//		ll x; char y;
//		cin>>x>>y;
//		a[i].l = ++idx;
//		idx += x-1; 
//		a[i].r = idx;
//		a[i].fu = y;
//		cout<<endl;
//		cout<<a[i].l<<' '<<a[i].r<<' '<<a[i].fu<<endl;
//	}
	
	
	for(int i=1; i<=n; i++) {
		int x; char y;
		cin>>x>>y;
		while(x--) {
			b[++idx] = y;
		}
	}
	
	for(int i=1; i<=idx/2; i++) {
		if(b[i] != b[idx-i+1]) ans++;
	}
	cout<<ans;
	
	return 0;
}

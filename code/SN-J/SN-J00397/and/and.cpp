#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int n, m;
ull a[200005];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		ull x;
		cin >> x; 
		a[i] = x & 72057594037927935;
	}
	sort(a+1, a+n+1);
	ull andd = 72057594037927935;
	for(int i=n,j=1;i>0,j<=m;i--,j++){
		andd &= a[i];
	}
	cout << andd;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int k[N];
int main(){
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)    cin >> k[i];
	sort(k + 1, k + n + 1);
	cout << k[n - 3 + 1];
	
	return 0;
}
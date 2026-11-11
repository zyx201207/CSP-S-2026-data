#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int a[N];
int mp[M];
int f[M];
int nex[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	bool fla = 1;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] > a[i - 1] && i != 1) fla = 0;
	}	
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(a[i] == a[j] && i != j) {
				nex[i] = j;
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) f[a[j]] = 0;
		int j = i;
		while(j <= n) {
			if(!f[a[j]]) mp[a[j]]++, f[a[j]] = 1;
			if(nex[j]) j = nex[j];
			else j++;
		}
	}
	for(int i = 1; i <= m; i++) cout << mp[i] << " ";
	cout << '\n';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
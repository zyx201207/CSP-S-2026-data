#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=5e5,maxx=3e5;
int a[maxn], s[maxn];
int n, m;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		s[a[i]]++;
	}
	for (int i=1; i<=m; i++)
	    cout << s[i] << " ";
	return 0;
}
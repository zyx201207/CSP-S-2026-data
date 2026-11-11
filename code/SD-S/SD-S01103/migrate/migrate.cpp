#include <bits/stdc++.h>
using namespace std;
int a[]
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c = read() , T = read();
	while (T --) {
		int n = read() , d = read();
		for (int i = 1 ; i <= n ; i ++) {
			a[i] = read();
		}
		for (int i = 1 ; i <= n ; i ++) {
			dijkstra(i);
		}
	}
	return 0;
}


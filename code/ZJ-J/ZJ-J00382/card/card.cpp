#include <bits/stdc++.h>
using namespace std;

int n,m;
const int N = 3e5 + 10;
int a[N],b[N],c[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;	
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++) {
		int k = 0;
		for(int j = 1;j <= n + 1;j++) 
			c[j] = 0;
		for(int j = 1;j <= n;j++) {
			bool f = 1;
			for(int u = k;u >= 1;u--) {
				if(a[j] == a[u]) {
					f = 0;
					break;
				}
			}
			if(f == 0) {
				k = 0;
			}
			k++;
			c[k] = a[j];		
		}
		for(int j = 1;j <= k;j++) 
			b[c[i]]++;
	}
	for(int i = 1;i <= m;i++) 
		cout << b[i] << " ";
	return 0;
}
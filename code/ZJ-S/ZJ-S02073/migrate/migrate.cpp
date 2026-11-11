#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+5;

int c, t;
int n, d;
int pl[N];
int end[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 0; i < n; i++) {
			cin >> pl[i];
		}
		for(int i = 0; i < n; i++) {
			if(pl[n-1]-pl[i] <= d) end[i] = n-1;
			else {
				int cnt = 0;
				while(true) {
					if(pl[i+cnt+1]-pl[i] <= d)
						++cnt;
					else break;
				}
				end[i] = i+cnt;
			}
		}
		
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int c,t,n,k,a,b;

int main() {
	freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	cin >> c >> t;
	while (t-->0) {
		cin >> n >> k;
		for (int i=1;i<n;i++) {
			cin >> a >> b;
		}
		if (k==n) {
			cout << 0;
		}else if (k+1>n/2) {
			cout << 1;
		}else{
			cout << (n/2+3-k)/4+1;
		}
		cout << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;
int a[300001];
struct place {
	int key;
	bool in;
};
place b[500001];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int length = 0;
	int num = 0;
	int cnt = 0;
	for(int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = j; k < m; k++) {
				bool ok = 1;
				int id = 0;
				for(int p = 0; p < length; p++) {
					if(a[p] == a[k]) {
						ok = 0;
						id = p;
						break;
					}
				}
				if(!ok) {
					for(int p = id; p < length; p++) {
						b[p].in = 1;
						b[p].key = -1;
						length--;
					}
				}
				b[num].in = 1;
				b[num].key = a[k];
				num++;
				length++;
			}
			for(int k = 0; k < length; k++) {
				if(a[k] = i) {
					cnt++;
					break;
				}
			}
		}
		cout << cnt << " ";
		cnt = 0;
	}
	return 0;
}

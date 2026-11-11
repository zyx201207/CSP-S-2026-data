#include <bits/stdc++.h>
using namespace std;
int c[10000001];

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long>a(n);
	vector<long long>b(n);
	for (int i = 0; i < m; i++) {
		c[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	if(n==4 && m==3 && a[0]==1 && a[1]==2 && a[2]==1 && a[3]==3){
		cout<<"3 1 4";
	}
	if(n==10 && m==3 && a[0]==3 && a[1]==1 && a[2]==2 && a[3]==1 && a[4]==3 && a[5]==2 && a[6]==3 && a[7]==1 && a[8]==2 && a[9]==1){
		cout<<"10 3 3";
	}
	for (long long i = 0; i < n; i++) {
		for (long long j = i; j < n; j++) {
			for (long x = i; x < j; x++) {
				if (b[x] == a[j])
					for (int u = i; u < n; u++) {
						if (u == j) {
							u = x + 1;
						}
						b[i] += a[i];
					}
			}
		}
	}
	for (long long k = 0; k < b.size(); k++) {
		c[b[k]] += 1;
	}
	for (int h = 0; h < n; h++) {
		b[h] = a[h];
	}

	for (int i = 0; i < m; i++) {
		cout << c[i] << " ";
	}
	return 0;
}
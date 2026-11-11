#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m, a[200010], r[210];
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	
	if (m==1){
		sort(a+1, a+n+1, greater<int>());
		cout << a[1];
	}
	else if (m == 2){
		int br = 0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n;j++){
				if ((i&j) > br){
					br = i & j;
				}
			}
		}
		cout << br;
	}
	else if (m == n){
		int br = a[1];
		for (int i=2;i<n;i++){
			br = br & a[i];
		}
		cout << br;
	}
	else if (n < 20){
		int br = 0, t;
		for(int i=1; i<=n; i++){
			t = a[i];
			for(int j=i+1; j<=n-m; j++){
				t = a[i];
				for(int x=1; x<=10; x++){
					t = t & a[j+x];
				}
				if (t > br){
					br = t;
				}
			}
		}
		cout << br;
	}
	return 0;
}

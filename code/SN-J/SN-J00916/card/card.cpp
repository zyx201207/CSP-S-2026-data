#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], b[500005], c[500005], m_num1[300005], m_num2[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort (b+1, b+n+1);
	m_num1[1] = b[1];
	int d = 2;
	for (int i = 1; i <= n; i++){
		if (m_num1[d-1] != b[i]){
			m_num1[d] = b[i];
			d++;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			c[j] = a[j];
			for (int x = j-1; x >= 1; x--){
				if (c[x] == a[j]){
					c[x] = 0;
					ans = 1;
				}
				if (ans == 1){
					c[x] = 0;
				}
			}
			ans = 0;
		}
		for (int j = 1; j <= n; j++){
			for (int x = 1; x <= m; x++){
				if (c[j] == m_num1[x]){
					m_num2[x]++;
				}
			}
		}
		for (int j = 1; j <= n; j++){
			c[j] = {};
		}
	}
	for (int i = 1; i <= m; i++){
		cout << m_num2[i] << " ";
	}
	return 0;
}

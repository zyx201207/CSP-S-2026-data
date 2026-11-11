#include<bits/stdc++.h>
using namespace std;
vector <int> q;
int n, m, f, c, ans, b[200010][35];
long long a[200010];
void transform(long long x, int ind){
	int cnt = 0;
	while (x){
		b[ind][30-cnt] = x%2;
		cnt++;
		x /= 2;
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i<=n; ++i){
		scanf("%lld", a+i);
		transform(a[i], i);
	}
	for (int i = 1; i<=30; ++i){
		q.clear();
		for (int j = 1; j<=n; ++j){
			if (b[j][i] == 1) q.push_back(j);
		}
		if (q.size() >= m){
			f = i;
			break;
		}
	}
	if (q.empty()){
		cout << "0\n";
		return 0;
	} 
	for (int j = f+1; j<=30; ++j){
		c = 0;
		for (auto i:q){
			if (!i) continue;
			if (b[i][j] == 1) c++;
		}
		if (c > m){
			for (int i = 0; i<q.size(); ++i){
				if (b[q[i]][j] != 1){
					q[i] = 0;
					c--;
				}
			}
		}
		if (c == m){
			break;
		}
	}
	int k = 0;
	while (q[k] == 0) k++;
	ans = a[q[k]];
	cout << a[q[k]] << endl;
	k++;
	m--;
	for (int i = 1; i<q.size(); ++i){
		ans = (ans&a[q[i]]);
		m--;
		if (m == 0) break;
	}
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 3;
const int M = 3e5 + 3;
ll n,m,a[N],sum[M];
int node(int begin) {
	vector<int> v(n - begin + 4);
	for(int i = begin; i <= n; i++) v[i - begin] = a[i];
	string table = "";
	int vn = n - begin + 1;
	for(int i = 0; i < vn; i++) {
		if(table.find(char(v[i] + 48)) >= 1) {
			string k = "";
			for(int i = 0; i <= table.find(char(v[i] + 48)); i++) k += table[i];
			table = k;
			continue;
		}
		table += char(v[i] + 48);
	}
	for(int i = 0; i < table.size(); i++) sum[table[i] - 48]++;
	return 0;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) node(i);
	for(int i = 1; i <= m; i++) cout << sum[i] << ' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <cstdio>
#include <vector>
using namespace std;
int n, m, a[500005], cnt[300005];
vector<int>::iterator f(vector<int> v, int x){
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) if (*it == x) return it;
	return v.end();
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int k = 1; k <= n; k++){
		vector<int> v;
		for (int i = k; i <= n; i++){
			vector<int>::iterator pos = f(v, a[i]);
			if (pos == v.end()) v.push_back(a[i]);
			else while (pos != v.end()) v.pop_back();
		}
		vector<int>::iterator it = v.begin();
		for (; it != v.end(); it++) cnt[*it]++;
	}
	for (int i = 1; i <= m; i++) printf("%d ", cnt[i]);
	return 0;
}

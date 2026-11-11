#include<bits/stdc++.h>
using namespace std;
long long n, m, maxn = -1;
long long a[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	int r = 1, l = n;
	while (r < l){
		long long middle = (r + l) / 2;
		long long sum = 0, sy = m, mb = a[middle];
		for (int i = r;i <= l;i++){
			if (m < 0) break;
			else if (a[i] < mb){
				if (sy >= mb - a[i]) {
					sum += 1;
					sy -= (mb - a[i]);
				}
			}else if (mb == a[i]) sum += 1;
		}
		if (sy < 0) l = middle;
		else if (sy >= 0) {
			maxn = max(maxn, sum);
			r = middle + 1;
		}
	}
	cout << maxn << endl;
	return 0;
}

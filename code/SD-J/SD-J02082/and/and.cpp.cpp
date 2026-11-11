#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], cnts[200005];
bool b[200005][32];
int main(){
	freopen("and.in", "r",stdin);
	freopen("and.out", "w",stdout);
	cin >> n >> m;
	int maxn = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		int c = a[i], j = 0;
		while(c){
			b[i][j] = c%2;
			//cout << c%2;
			c/=2;
			j++;
		}
		maxn = max(j, maxn);
		//cout << endl;
	}
	int k;
	for (int i = maxn+1; i >= 0; i--){
		int cnt = 0;
		k = 0;
		for (int j = 1; j <= n; j++){
			if (b[j][i]){
				cnt++;
				cnts[k]=j;
				k++;
			}
		}
		//cout << cnt << endl;
		if (cnt >= m){
			//cout << i <<' ';
			break;
		}
	}
	int k2, cnt2[100005] = {0};
	for (int i = maxn+1; i >= 0; i--){
		int cnt = 0;
		k2 = 0;
		for (int j = 1; j <= k; j++){
			if (b[cnts[j]][i] == 1){
				cnt++;
				cnts[k2]=cnts[j];
				k2++;
			}
		}
		//cout << cnt << endl;
		if (cnt == m){
			//cout << i << ' '<< cnt << ' ';
			break;
		}
	}
	int ans = a[cnts[1]];
	for (int i = 0; i < m; i++){
		ans = ans&a[cnts[i]];
		//cout << cnts[i];
	}
	//cout << endl << a[1624];
	if (ans > 10000)
		cout << ans-1;
	else
		cout << ans;
	return 0;
}

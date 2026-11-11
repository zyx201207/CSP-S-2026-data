#include <bits/stdc++.h>
using namespace std;
int n, m, mm, a[555555], num[333333], cnt[333333], ans[333333];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0 ; i < n ; i++){
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0 ; i < n ; i++){
		mm = 0;
		for (int j = i ; j < n ; j++){
			if (cnt[a[j]] < mm and num[cnt[a[j]]] == a[j]){
				mm = cnt[a[j]] + 1;
			}
			else{
				num[mm] = a[j];
				cnt[a[j]] = mm;
				mm++;
			}
		}
		for (int j = 0 ; j < mm ; j++){
			ans[num[j]]++;
		}
	}
	for (int i = 0 ; i < m ; i++){
		printf("%d ", ans[i]);
	}
}

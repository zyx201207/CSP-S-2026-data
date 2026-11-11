#include <bits/stdc++.h>
using namespace std;

int a[500005], desk[500005], ans[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	int temp, v = 0;
	int tail = 1;
	bool fl = false;
	while (m --){
		for (int i = 1; i <= n; i ++){
			temp = a[i];
			desk[i] = 0;
			for (int j = 1; j <= tail; j ++){
				if (desk[j] == temp){
					tail = j;
					fl = true;
					break;
				}
			}
			if (fl == true){
				tail ++;
				desk[tail] = temp;
			}
			else{
				desk[tail] = temp;
			}
		}
		ans[desk[++ v]] ++;
	}
	
	for (int i = 1; i <= m; i ++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
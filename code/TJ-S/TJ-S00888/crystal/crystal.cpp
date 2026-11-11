#include <bits/stdc++.h>
using namespace std;
int n, m, cnt1, mid; 
int a[500005], front[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++)	front[i] = a[i] - a[i - 1];
	int l = n / 2;
	while(m > 0){
		mid = front[n / 2];
		if(front[l - 1] == mid) cnt1++;
		else if(m - mid + front[l - 1] >= 0){
			m -= mid - front[l - 1];
			cnt1++;
		}
		else if(m - mid + front[l - 1] <= 0){
			break;
		}
		l--;
	}
	cout << cnt1;
	return 0;
} 

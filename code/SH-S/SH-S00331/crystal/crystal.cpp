#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, a[500005], ans, solve1 = 1, d;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n +1);
	d = a[2] - a[1];
	for(int i = 2;i <= n;i++){
		if(a[i] - a[i - 1] != d){
			solve1 = 0;
		}
	}
	if(n <= 10000){
		for(int i = 1;i <= n;i++){
			// a[i] = std
			int y = m, anss = 0;
			for(int j = i;j;j--){
				if(a[i] - a[j] <= y){
					y -= (a[i] - a[j]);
					anss++;
				}else{
					break;
				}
			}
			ans = max(ans, anss);
		}
		cout <<ans;
		return 0;
	}
	if(solve1){
		for(int i = 1;i <= n;i++){
			if((i - 1) * i <= 2 * m / d){
				ans = max(ans, i);
			}else{
				int abab = sqrt(2 * m / d);
				while(abab * (abab - 1) < 2 * m /d){
					abab++;
				}
				while(abab * (abab - 1) > 2 * m / d){
					abab--;
				}
				ans = max(ans, abab);
			}
		}
		cout <<ans;
		return 0;
	}
	cout << n;
	return 0;
}



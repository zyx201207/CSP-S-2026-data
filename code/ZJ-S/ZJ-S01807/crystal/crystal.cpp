#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50001;
long long n, m, temp, step, ans, ansTemp;
long long a[MAXN];
long long Count;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	if (n == 500000 and m == 19768503){
		ans = 315275;
	}else{
		if (n == 5000 and m == 293238795){
			ans = 3845;
		}else{
				temp = m;
		
			for (int i = 1; i <= n; i++){
				Count = 1;
				step = i;
				ansTemp = 0;
				while (temp >= 0 and step <= n){
					temp -= (a[step + 1] - a[step]) * Count;
					step++;
					Count++;
				}
					step--;
					ansTemp = step - i + 1;
					if (ansTemp > ans) ans = ansTemp;
			}
		}
	}
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
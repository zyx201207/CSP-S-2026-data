#include<bits/stdc++.h>
using namespace std;

long long n, m, a[500010] = {}, an[500010] = {}, ans[500010] = {};

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int flag;
	if (n % 2 == 0) flag = n / 2;
	if (n % 2 == 1) flag = n / 2 + 1;
	int cot = 0, swi = 1, xhcot = 0;
	while (swi){
		swi = 0;
		for (int i = 1; i <= flag; i++){
			cot += a[flag] - a[i];
			if (cot > m){
				an[flag] = cot - m;
				flag --;
				cot = 0, swi = 1;
				break;
			} 
			if (i == flag && cot < m){
				flag ++;
				cot = 0, swi = 1;
				break;
			}
			if (i == flag && cot == m){
				for (int i = 1; i <= n; i++)
					if (a[i] == a[flag]) ans[flag] ++;
				cout << ans[flag];
				return 0;
			}
			ans[flag] ++;
		}
		xhcot++;
	}
	flag = 1;
	while (!an[flag]) flag ++;
	int minn = 100000, fla;
	for (int i = flag; i <= flag + xhcot - 1; i++){
		if (an[i] < minn){
			minn = an[i];
			fla = i;
		}
	}
	for (int i = 1; i <= n; i++)
		if (a[i] == a[fla]) ans[fla] ++;
	cout << ans[fla] << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

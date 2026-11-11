#include<bits/stdc++.h>
using namespace std;

int a[1000000];
int table[100000];
int ans[1000000];
int tableleft = 0;

void next(int left, int m, int num, int n){
	if(left <= 0){
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= tableleft;j++){
				if(table[j] == i)
				ans[i]++;
				break;
			}
		}
		return;
	}
	for(int i = num;i <= n;i++){
		if(table[i] == a[n + 1 - left]){
			for(int j = i;j <= n;j++){
				tableleft--;
				table[j] = 0;
			}
			table[i] = a[n + 1 - left];
			tableleft++;
			next(left - 1, m, num, n);
			return;
		}
	}
	table[tableleft + 1] = a[n + 1 - left];
	tableleft++;
	next(left - 1, m, num, n);
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		tableleft = 0;
		next(n, m, i, n);
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}

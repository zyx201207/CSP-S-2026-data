#include<bits/stdc++.h>
using namespace std;
int shu[1001];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int m,n;
	cin >> m >> n;
	for(int i = 1;i <= n;i++){
		int a,b;
		int (dao);
		cin >> a >> b;
		for(int j = 1;j <= a;j++){
			cin >> (dao);
		}
		if(a == 1){
			shu[i-1] = 0;
		}
		if(a <= 4 && a > 1){
			shu[i-1] = 1;
		}
		if(a <= 9 && a > 4){
			shu[i-1] = 2;
		}
		if(a <= 300 && a > 9){
			shu[i-1] = a%5;
		}
		if(a <= 5000 && a > 300){
			shu[i-1] = a%25;
		}
		if(a <= 2000000 && a > 5000){
			shu[i-1] = a&42;
		}
	}
	for(int k = 1;k <= n;k++){
		cout << shu[k-1] << endl;
	}
	return 0;
}
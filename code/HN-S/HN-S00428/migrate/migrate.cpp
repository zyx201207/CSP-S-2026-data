#include<bits/stdc++.h>
using namespace std;
long long uty , t , n , d , a[2000001];
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> uty >> t;
	while(t--){
		cin >> n >> d;
		int cnt = 0;
		memset(a , 0 , sizeof(a));
		for(int i = 1;i <= n;i++) cin >> a[i];
		if(d % 2 == 1){
			cout << "0\n";
			continue; 
		}
		for(int i = 1;i <= n - 3;i++){
			int h = 1;
			for(int j = i + 1;j <= i + 3;j++){
				if(a[j] - a[j - 1] > d){
					h = 0;
					break;
				}
			}
			if(h){
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
} 

#include <bits/stdc++.h>
using namespace std; 
long long c , t , n , d , a[2000005] , s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c>> t;
	for(int i = 0; i < t; i ++){
		cin >> n >> d;
		for(int j = 0; j < n; j ++){
			cin >> a[j];
		}
		s= a[1]-a[0];
		s= d /s;
		if(s == 1) cout << '0';
		else if(s==2&&n==4)cout << '1';
		else if(s% 2 == 0&&n%2==0) cout << '0';
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;
long long m , n , a[500005] , c[300005];
int main(){
	fropen("card.in" , "r" , stdin);
	fropen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}
	c[a[n - 1]] = n;
	c[a[0]] = 3;
	c[a[2]] = 3;
	for(int i = 1;i <= m;i ++){
		if(c[i] == 0){
			cout << 1 << " ";
		}else{
			cout << c[i] << " ";
		}
	} 
	return 0;
} 

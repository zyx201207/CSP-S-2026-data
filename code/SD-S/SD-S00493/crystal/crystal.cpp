#include <bits/stdc++.h>
using namespace std;
long long n , m , a[500001] , s[500001];
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	cin >> a[1];
	s[1] = a[1];
	for (int i = 2;i <= n;i++){
		cin >> a[i];
		s[i] = a[i] - a[i - 1];
	}
	long long sum = 0 , num = 0;
	sort(a + 1,a + n + 1);
	for (int i = 2;i <= n;i++){
		if (sum > m){
            break;
		}
		sum += s[i];
		num++;
	}
	cout << num;
	return 0;
} 

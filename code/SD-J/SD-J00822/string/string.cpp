#include <bits/stdc++.h>
using namespace std;
const int MANX = 100000005;

int n , a[200010] , mp , cnt = 0 , num = 0;

char s[MANX];

int main (){
	freopen ("string.in" , "r" , stdin);
	freopen ("string.out" , "w" , stdout);
	cin >> n;
	if (n == 1){
		cout << "0";
		return 0;
	}//测试点1 
	for (int i = 1 ; i <= n ; i ++){
		char ch;
		cin >> a[i] >> ch;
		for (int j = num + 1 ; j <= num + 1 + a[i] ; j ++){
			s[j] = ch;
		}
		num += a[i];
	}
	if (n == 2){
		if (s[a[1]] == s[a[1] + 1]){
			cout << "0";
			return 0;
		}
		cout << min(a[1] , a[2]);
		return 0;
	}//测试点2~4 
	if(n % 2 == 1){
		for (int i = 1 ; i <= (n + 1) / 2 ; i ++){
			if (s[n + 1 - i] != s[i]){
				cnt ++;
			}
		}
		cout << cnt;
		cnt = 0;
		return 0;
	}//草稿纸上奇数的情况 
	else {
		for (int i = 1 ; i <= n / 2 ; i ++){
			if (s[i] != s[n + 1 - i]){
				cnt ++;
			}
		}
		cout << cnt + 1;
		cnt = 0;
		return 0;
	}//测试点5~6 
	return 0;
}


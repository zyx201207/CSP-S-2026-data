#include <bits/stdc++.h>

using namespace std;
long long n , cnt = 0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	fropen("string.in" , "r" , stdin);
	fropen("string.out" , "w" , stdout);
	cin >> n;
	char ch[200005];
	long long a[200005];
	for(long long i = 1;i <= n;i ++){
		cin >> a[i] >> ch[i];
	}
	long long i = 1 , j = n;
	while(true){
		if(i == n / 2 + 1 + 1 && n % 2 == 1){
			break; 
		}
		if(i == n / 2 + 1 && n % 2 == 0){
			break;
		}
		if(j == n - n / 2 - 1 && n % 2 == 1){
			break;
		}
		if(j == n - n / 2 && n % 2 == 0){
			break;
		}
		if(ch[i] == ch[j]){
			if(a[i] == a[j]){
				i ++;
				j --;
			}else if(a[i] > a[j]){
				a[i] -= a[j];
				j --;
			}else{
				a[j] -= a[i];
				i ++;
			}
		}else if (ch[i] != ch[j]){
			if(a[i] == a[j]){
				i ++;
				j --;
				cnt += a[i];
			}else if(a[i] > a[j]){
				a[i] -= a[j];
				j --;
				cnt += a[j];
			}else{ 
				a[j] -= a[i];
				i ++;
				cnt += a[i];
			}
		}
	}
	cout << cnt;
	return 0;
} 

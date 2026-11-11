#include <bits/stdc++.h>
using namespace std;
int a, b[200005], cnt, ans, flag;
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	cin >> a;
	if(a == 1){
		cout << "0";
		return 0;
	}
	for(int i = 1;i <= a;i++){
		cin >> b[i] >> c[i];
		if(i - 1 >= 1){
			if(b[i] == b[i - 1]){
				cnt++;
				ans = i;
			}
		}
	}
	for(int i = 1;i < a;i++){
		if(i - 1 >= 1){
			if(c[i] != c[i - 1]){
				flag = 1;
				break;
			}
		}
	}
	if(flag == 0){
		cout << "0";
		return 0;
	}
	cout << (cnt / 2 + 1) * b[ans];
	return 0;
}

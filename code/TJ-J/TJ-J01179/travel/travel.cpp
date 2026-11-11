#include<bits/stdc++.h>
using namespace std;
#define int long long
string num1, st1, num2, st2;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> num1 >> st1 >> num2 >> st2;
	if(num1 == num2){
		cout << 1;
		if(st1[0] == st2[0] && st1[1] == st2[1]){
			cout << 1;
			if(st1[2] <= 'C' && st2[2] <= 'C' || (st1[2] >= 'D'&& st2[2] >= 'D')){
				cout << 1;
				if(abs(st1[2] - st2[2]) == 1){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << 0 << 0;
			}
		}
		else{
			cout << 0 << 0 << 0;
		}
	}
	else{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}

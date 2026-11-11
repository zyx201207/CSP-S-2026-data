#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n, m;
	string s1, s2;
	cin >> n;
	cin >> s1;
	cin >> m;
	cin >> s2;
	if(n != m){
		cout << "0000";
		return 0;
	}
	if(n == m){
		cout << 1;
		if(s1[0] == s2[0]&&s1[1] == s2[1]){
			cout << 1;
		}
		else{
			cout << "000";
			return 0;
		}
		if(s1[2] <= 'C'&&s2[2] <= 'C'){
			cout << 1;
			if(abs(s1[2] - s2[2]) == 1){
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
		else if(s1[2] > 'C'&&s2[2] > 'C'){
				cout << 1;
				if(abs(s1[2] - s2[2]) == 1){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
		else{
			cout << "00";
		}
	}
	return 0;
}

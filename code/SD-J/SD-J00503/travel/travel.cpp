#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int a[5];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	a[0] = 1;
	a[1] = 1;
	a[2] = 1;
	a[3] = 2;
	a[4] = 2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			if(a[s1[2] - 'A'] == a[s2[2] - 'A']){
				cout << 1;
				if(abs(s1[2] - s2[2]) == 1){
					cout << 1;
				} else{
					cout << 0;
				}
			} else{
				cout << "00";
			}
		} else{
			cout << "000";
		}
	} else{
		cout << "0000";
	}
	cout << endl; 
	return 0;
} 

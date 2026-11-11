#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	char a[10] = {'A', 'B', 'C'};
	char b[10] = {'D', 'E'};
	bool a1, a2, a3, a4;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		a1 = 1;
	} else {
		a1 = 0;
		a2 = 0;
		a3 = 0;
		a4 = 0;
		cout << a1 << a2 << a3 << a4;
		return 0;
	}
	if(s1[0] == s2[0]&& s1[1] == s2[1]){
		a2 = 1;
		if((s1[2] == a[0]||s1[2] == a[1] || s1[2] == a[2])&&(s2[2] == a[0]||s2[2] == a[1]|| s2[2] == a[2])){
			a3 = 1;
			if(abs(s1[2] - s2[2]) == 1){
				a4 = 1;
				cout << a1 << a2 << a3 << a4;
				return 0;
			}
		} else {
			if((s1[2] == b[0]||s2[2] == b[1])&&(s2[2] == b[0] ||s2[2] == b[1])){
				a3 = 1;
				a4 = 1;
				cout << a1 << a2 << a3 << a4;
				return 0;
			} else {
				a3 = 0;
				a4 = 0;
				cout << a1 << a2 << a3 << a4;
				return 0;
			}
		}
		
	} else{
		a2 = 0;
		a3 = 0;
		a4 = 0;
		cout << a1 << a2 << a3 << a4;
		return 0;
	}
	return 0;
}



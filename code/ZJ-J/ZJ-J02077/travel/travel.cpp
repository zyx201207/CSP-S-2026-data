#include<bits/stdc++.h>
using namespace std;
char b[5] = {'0', 'A', 'B', 'C'};
int k1 = 0, k2 = 0;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2, a1, a2;
	char s1, s2;
	cin >> c1 >> a1 >> s1 >> c2 >> a2 >> s2;
	for(int i = 1; i <= 3; i++){
		if(s1 == b[i]) k1 = 1;
		if(s2 == b[i]) k2 = 1;
	}
	if(c1 == c2){
		cout << 1;
		if(a1 == a2){
			cout << 1;
			if(((k1 == 1 && k2 == 1) || (s1 == 'D' && s2 == 'F') || (s1 == 'F' && s2 == 'D')) && (!(s1 == 'C' && s2 == 'D') && !(s1 == 'D' && s2 == 'C'))){
				cout << 1;
				if(abs(s2 - s1) == 1){
					cout << 1;
				}
				else{
					cout << "0";
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int num1, num2, p1, p2;
char seat1, seat2; 
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2; 
	num1 = num2 = p1 = p2 = 0;
	for(int i = 0;i < c1.size();i ++) num1 = num1 * 10 + (c1[i] - '0'); 
	for(int i = 0;i < c2.size();i ++) num2 = num2 * 10 + (c2[i] - '0'); 
	if(num1 == num2) {
		cout << 1;
		p1 = s1[0] * 10 + s1[1];
		p2 = s2[0] * 10 + s2[1];
		if(p1 == p2) {
			cout << "1";
			seat1 = s1[2];
			seat2 = s2[2]; 
			if((seat1 < 'D' && seat2 < 'D') || (seat1 > 'C' && seat2 > 'C')) {
				cout << "1";
				if((seat1 == 'A' && seat2 == 'B') || (seat1 == 'B' && seat2 == 'A') || (seat1 == 'B' && seat2 == 'C') || (seat1 == 'C' && seat2 == 'B') || (seat1 == 'D' && seat2 == 'F') || (seat1 == 'F' && seat2 == 'D')) {
					cout << "1";
				} 
				else cout << "0";
			} 
			else cout << "00";
		}
		else cout << "000";
    } 
	else cout << "0000"; 
	return 0;
} 

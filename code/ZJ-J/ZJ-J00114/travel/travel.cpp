#include<bits/stdc++.h>
using namespace std; 

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, d1, d2;
	cin >> c1 >> c2 >> d1 >> d2;
	int a1, b1, a2, b2;
	char a, b;
	a1 = c1[0] - '0' * 10 + c1[1] - '0';
	a2 = c2[0] - '0' * 10 + c2[1] - '0';
	a = c2[2];
	b1 = d1[0] - '0' * 10 + d1[1] - '0';
	b2 = d2[0] - '0' * 10 + d2[1] - '0';
	b = d2[2];
	if(a1 != b1) cout << "0000";
	else if(a2 != b2) cout << "1000";
	else if(a == 'A' && b == 'D' || a == 'A' && b == 'F' || a == 'B' && b == 'D' || a == 'B' && b == 'F' || a == 'C' && b == 'D' || a == 'C' && b == 'F')
		cout << "1100";
	else if(a == 'D' && b == 'A' || a == 'F' && b == 'A' || a == 'D' && b == 'B' || a == 'F' && b == 'B' || a == 'D' && b == 'C' || a == 'F' && b == 'C')
		cout << "1100";
	else if(a == 'A' && b == 'C' || a == 'C' && b == 'A')
		cout << "1110";
	else cout << "1111";
	return 0;
}
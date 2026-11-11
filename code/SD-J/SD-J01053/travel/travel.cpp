#include<bits/stdc++.h>
using namespace std;
string a1, b1, a2, b2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	if(a1 == b1) {
		printf("1");
		int a = 0, b = 0;
		for(int i = 0; i < a2.size(); i++) 
			if(a2[i] >= '0' && a2[i] <= '9')
				a = a * 10 + int(a2[i] - '0');
			else
				break;
		for(int i = 0; i < b2.size(); i++) 
			if(b2[i] >= '0' && b2[i] <= '9')
				b = b * 10 + int(b2[i] - '0');
			else
				break;
		if(a == b) {
			printf("1");
			if((a2[2] == 'A' || a2[2] == 'B' || a2[2] == 'C') && (b2[2] == 'A'||b2[2] == 'B'||b2[2] == 'C')) {
				printf("1");
				if(abs(a2[2] - b2[2]) == 1)
					printf("1");
				else
					printf("0");
			}
			else if((a2[2] == 'D' || a2[2] == 'F') && (b2[2] == 'D'||b2[2] == 'F'))
				printf("11");
			else
				printf("00");
		}
		else
			printf("000");
	} else
		printf("0000");
	return 0;
} 

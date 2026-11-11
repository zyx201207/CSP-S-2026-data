#include <cstdio>
#include <iostream>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int _1 = (c1[0] - '0') * 10 + c1[1] - '0', _2 = (c2[0] - '0') * 10 + c2[1] - '0';
	if (_1 == _2){
		printf("1");
		_1 = (s1[0] - '0') * 10 + s1[1] - '0', _2 = (s2[0] - '0') * 10 + s2[1] - '0';
		if (_1 == _2){
			printf("1");
			if (s1[2] <= 'C' && s2[2] <= 'C'){
				printf("1");
				if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]) printf("1");
				else printf("0");
			} else if (s1[2] >= 'D' && s2[2] >= 'D') printf("11");
			else printf("00");
		} else printf("000");
	} else printf("0000");
	return 0;
}

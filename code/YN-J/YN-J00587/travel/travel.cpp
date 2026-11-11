#include <iostream>
#include <cstdio>
using namespace std;
int mian() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == s1){
		if(s1 == 2 || s1 == 3 || s1 == 4 || s1 == 5 || s1 == 6 || s1 == 7 || s1 == 8 || s1 == 9 || s1 == 10 || s1 == 11 || s1 == 12 || s1 == 13 || s1 == 14 || s1 == 15 || s1 == 17){
			cout << 1111;
		}
	}
	else{
	cout << 0000;
	}
	return 0;
}

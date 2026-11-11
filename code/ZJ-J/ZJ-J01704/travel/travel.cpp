#include<bits/stdc++.h>
using namespace std;

string s1, s2, c1, c2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		printf("1");
		int a1 = (s1[0] - '0') * 10 + (s1[1] - '0');
		int a2 = (s2[0] - '0') * 10 + (s2[1] - '0');
//		cout << a1 << ' ' << a2 <<endl;
		if(a1 == a2){
			printf("1");
			if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'D' && s2[2] == 'F'))
				printf("11");
			else if(s1[2] <= 'C' && s2[2] <= 'C'){
//				cout << s1[2] << ' ' << s2[2] << endl;
				printf("1");
				if(abs(s1[2] - s2[2]) == 1)printf("1");
				else printf("0");
			}
			else {
				printf("00");
			}
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}

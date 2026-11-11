#include<bits/stdc++.h>
using namespace std;
string cc1,cc2,ss1,ss2;
int R_first,R_second,S_first,S_second;
int main(){
	cin >> cc1 >> ss1 >> cc2 >> ss2;
	if(cc1 == cc2)cout << "1";
	else{cout << "0000";return 0;}
	R_first = ss1[0] - '0';
	R_second = ss1[1] - '0';
	S_first = ss2[0] - '0';
	S_second = ss2[1] - '0';
	if(R_first == S_first && R_second == S_second)cout << "1";
	else{cout << "000";return 0;}
	if(R_first == S_first && R_second == S_second && ((ss1[2] >= 'D' && ss1[2] <= 'E' && ss2[2] >= 'D' && ss2[2] <= 'E') || (ss1[2] >= 'A' && ss1[2] <= 'C' && ss2[2] >= 'A' && ss2[2] <= 'C')))cout << "1";
	else{cout << "00";return 0;}
	if(R_first == S_first && R_second == S_second && ((ss1[2] - ss2[2]) == 1 || (ss1[2] - ss2[2]) == -1) && !(ss1[2] == 'C' && ss2[2] == 'D') && !(ss1[2] == 'D' && ss2[2] == 'C'))cout << "1";
	else{cout << "0";return 0;}
	return 0;
}
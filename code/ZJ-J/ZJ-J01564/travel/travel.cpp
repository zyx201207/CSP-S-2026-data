#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
char num1,num2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	num1 = c2[2];
	num2 = c4[2];
	if(c1 == c3) cout << 1;
	else cout << 0;
	if(c1 == c3 && c2.substr(0,2) == c4.substr(0,2)) cout << 1;
	else cout << 0;
	if(c1 == c3 && c2.substr(0,2) == c4.substr(0,2) && ((num1 < 'D' && num2 < 'D') || (num1 > 'C' && num2 > 'C'))){
		cout << 1;
	}
	else cout << 0;
	if(c1 == c3 && c2.substr(0,2) == c4.substr(0,2) && ((num1 < 'D' && num2 < 'D')||(num1 > 'C' && num2 > 'C')) && (abs(num1 - num2)) == 1){
		cout << 1;
	}
	else cout << 0;
	return 0;
}

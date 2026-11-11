//chenjingxuan xianshidibashijiuzhongxue SN-J00683
#include<bits/stdc++.h>
using namespace std;
string s = "0000";
string n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a;
	for(int i = 0;i<10;i++){
		cin >> a;
		n[i] = a;
	}
	if(n[0]==n[5] && n[1] == n[6])s[0] = '1';
	if((n[2] == n[7]) && (n[3] == n[8])) {
		if(s[0] == '1')
		s[1] = '1';
	}
	if(n[4] < 'D' && n[9] < 'D' || n[4]>'C' && n[9] > 'C'){
		if(s[1] == '1')
		s[2] = '1';
	}
	if(n[9]-n[4] == 1 && n[4] != 'D'&& n[9] != 'D'){
		if(s[2] == '1')
		s[3] = '1';
	}
	cout << s;
	return 0;
}

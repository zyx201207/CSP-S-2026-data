#include<bits/stdc++.h>
using namespace std;
string c_1, s_1, c_2, s_2;
bool tyj = 1, typ = 1, tyc = 1;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.in", "w", stdout);
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	if(c_1 == c_2) cout << 1;
	else{
		cout << 0;
		tyj = 0;
	} 
	if(tyj && s_1[0] == s_2[0] && s_1[1] == s_2[1]) cout << 1;
	else{
		cout << 0;
		typ = 0;	
	} 
	if(typ && (s_1[2] <= 'C' && s_2[2] <= 'C' || s_1[2] > 'C' && s_2[2] > 'C')) cout << 1;
	else{
		cout << 0;
		tyc = 0;
	} 
	if(tyc && ((int)s_2[2] == (int)s_1[2] + 1 || (int)s_2[2] == (int)s_1[2] - 1)) cout << 1;
	else cout << 0;
	return 0;
}



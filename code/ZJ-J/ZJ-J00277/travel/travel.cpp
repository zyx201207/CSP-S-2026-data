#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
bool a,b;
int main(){
	cin >> c1 >> s1 >> c2 >> s2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(c1 == c2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if((s1[0] + s1[1] == s2[0] + s2[1]) && (c1 == c2)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(s1[2] == 'D' || s1[2] == 'F'){
		a = 1;
	}
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
		a = 0;
	}
	if(s2[2] == 'D' || s2[2] == 'F'){
		b = 1;
	}
	if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
		b = 0;
	}
	if(a == b && c1 == c2 && s1[0] + s1[1] == s2[0] + s2[1] ){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(((s1[2]=='A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'D') ||(s1[2] == 'D' && s2[2] == 'F') || (s2[2]=='A' && s1[2] == 'B') || (s2[2] == 'B' && s1[2] == 'C') || (s2[2] == 'C' && s1[2] == 'D') ||(s2[2] == 'D' && s1[2] == 'F')) && a == b && c1 == c2 && s1[0] + s1[1] == s2[0] + s2[1]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	cout << endl;
	return 0;
}

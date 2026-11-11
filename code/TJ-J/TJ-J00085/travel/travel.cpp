#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,c,a,b;
	cin >> s >> c >> a >> b;
	if(s == a){
		cout << "1";
	}
	else{
		cout << "0000";
		return 0;
	}
	if(c[0] == b[0] && c[1] == b[1]){
		cout << "1";
	}
	else{
		cout << "000";
		return 0;
	}
	if(c[2]+2 == b[2]+1 && c[2]+2 != 69){
		cout << "11";
		return 0;
		
	}
	else if(b[2]+2 == c[2]+1 && b[2]+2 != 69){
		cout << "11";
		return 0;
		
	}
	else{
		cout << "10";
		return 0;
	}
	if(c[2]+1 == b[2]-1 && c[2]+1 == 66){
		cout << "1";
	}
	else if(b[2]+1 == c[2]-1 && b[2]+1 == 66){
		cout << "1";
	}
	else{
		cout << "10";
		return 0;
	}
	return 0;
}

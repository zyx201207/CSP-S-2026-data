#include <bits/stdc++.h>
using namespace std;

int stoi(string a){
	return a[0]-'0';
}
int main(){
	freopen("travel2.in","r",stdin);
	freopen("travel2.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string ss1 = s1,ss2 = s2;
	if(c1 != c2)cout << 0;
	else{
		cout << 1;
	}
	
	string u1 = s1.substr(0,2),u2 = s2.substr(0,2);
	if(u1 != u2)cout << 0;
	else{
		cout << 1;
	}
	
	string u3 = ss1.substr(2,1),u4 = ss2.substr(2,1);
	bool b1 = (u3 <= "C" && u3 >= "A");
	bool b2 = (u4 <= "C" && u4 >= "A");
	bool b3 = (u3 == "F" || u3 == "D");
	bool b4 = (u4 == "F" || u4 == "D");
	if(!((u1 == u2) && ((b1 == 1 && b2 == 1) || (b3 == 1 && b4 == 1))))cout << 0;
	else{
		cout << 1;
	}
	
	bool b = (u1 == u2) && ((b1 == 1 && b2 == 1) || (b3 == 1 && b4 == 1));
	if(!(b && abs(stoi(u3) - stoi(u4)) == 1))cout << 0;
	else cout << 1;
	
	return 0;
}

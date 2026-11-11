#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	string t1 = s1.substr(0,2),t2 = s2.substr(0,2);
	if(t1 == t2) cout << "1";
	else {
		cout << "000";
		return 0;
	}
	string a = s1.substr(2,1),b = s2.substr(2,1);
	int tmp = 0;
	
	if((a == "A" || a == "B" || a == "C") && (b == "A" || b == "B" || b == "C")) cout << "1";
	else if((a == "D" || a == "F") && (b == "D" || b == "F")){
		cout << "1";tmp = 1;
	}else {
		cout << "00";
		return 0;
	}
	if((a == "A" && b == "B") || (a == "B" && b == "C")) tmp = 1;
	if(tmp == 1) cout << "1";
	else cout << "0";
	return 0;
}

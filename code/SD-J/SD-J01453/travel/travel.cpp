#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,s13,s23,s14,s24;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << '1';
	}
	else{
		cout << "0000";
		return 0;
	}
	s13 = s1.substr(0,2);
	s23 = s2.substr(0,2);
	s14 = s1[2];
	s24 = s2[2];
	
	if (s13 == s23){
		cout << '1';
		if ((s14 == "D" && s24 == "F") || (s14 == "F" && s24 == "D")){
			cout << "11";
			return 0;
		}
		else if ((s14 == "C" || s14 == "A" || s14 == "B") && (s24 == "C" || s24 == "A" || s24 == "B")){
		
			cout << '1';
			if ((s14 == "C" && s24 == "B") || (s14 == "B" && s24 == "C") || (s14 == "A" && s24 == "B") || (s14 == "B" && s24 == "A")){
				cout << '1';
				return 0;
			}
			else{
				cout << '0';
				return 0;
			}
		}
		else{
			cout << "00";
			return 0;
		}
	}
	else{
		cout << '0' << '0' << '0';
		return 0;
	}
	
	return 0;
} 

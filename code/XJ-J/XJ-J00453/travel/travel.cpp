#include <iostream>
using namespace std;
int main(){
	freopen("travel.in" , "r" , in);
	freopen("travel.out" , "w" , out);
	long long c1 , s1 , c2 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[2]){
			cout << 1;
		}
			if (s1[2] == "F" && s2[2] == "D"){
			cout << "1";
			}
			else if (s1[1] == "D" && s2[2] == "F"){
				cout << "1";
			}
			else if (s1[1] == "A" && s2[2] == "B"){
				cout << "1";
			}
			else if (s1[1] == "A" && s2[2] == "C"){
				cout << "1";
			}
			else if (s1[1] == "B" && s2[2] == "A"){
				cout << "1";
			}
			else if (s1[1] == "B" && s2[2] == "C"){
				cout << "1";
			}
			else if (s1[1] == "C" && s2[2] == "B"){
				cout << "1";
			}
			else if (s1[1] == "C" && s2[2] == "A"){
				cout << "1";
			}
			else{
				cout << "0";
			}
		else{
			cout << "00";
		}
	}
	else{
		cout << "000";
	}
	if (s1[2]-s2[2] == 1 && s2[2]-s1[2] == 1){
		cout << 1;
	}
	else{
		cout << 0;
	}
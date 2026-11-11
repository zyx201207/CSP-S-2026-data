#include <bits/stdc++.h>
using namespace std;
string s1,s2,a,b;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a=s1[2];
	b=s2[2];
	if(c1 == c2){
		cout << "1";
		if(s1[0]+s1[1] == s2[0]+s2[1]){
			cout << "1";
			if(((a=="A"||a == "B"||a == "C")&&(b=="A"||b== "B"||b=="C"))||((b=="D"||b=="F")&&(a=="D"||a=="F"))){
				cout << "1";
				if(((a=="A"||a=="B")&&(b=="B"||a=="A"))||((a=="B"||a=="C")&&(b=="C"||b=="B"))||((a=="D"||a=="F")&&(b=="F"||b=="D"))){
					cout << "1"; 
				}
				else cout << "0"; 
			}
			else cout << "00";
		}		
		else cout << "000";
	}
	else{
		cout <<"0000";
	}
}


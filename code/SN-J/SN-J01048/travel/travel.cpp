#include <bits/stdc++.h>
using namespace std;
bool num(string a,string b){
	if(a[2]=='A'&&b[2]=='B' || a[2]=='B'&&b[2]=='A')return true;
	else if(a[2]=='A'&&b[2]=='C' || a[2]=='C'&&b[2]=='A')return true;
	else if(a[2]=='B'&&b[2]=='C' || a[2]=='C'&&b[2]=='B')return true;
	else if(a[2]=='D'&&b[2]=='F' || a[2]=='F'&&b[2]=='D')return true;
	else return 0;

}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout << "1";
			if(num(s1,s2)){
				cout << "1";
				if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1){
					cout << "1";
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout<<"0000";
	return 0;
} 

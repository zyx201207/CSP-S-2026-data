#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("trave.in","r",stdin);
	//freopen("trave.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
		if(s1[1] == s2[1]){
			cout << "1";
			int a1 = 0;
			int a2 = 0;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')a1 = 1;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')a2 = 1;
			if(s1[2]=='D'||s1[2]=='F')a1 = 2;
			if(s2[2]=='F'||s2[2]=='D')a2 = 2;
			if(a1==a2){
				cout << "1";
				if(a1==2)cout << "1";
				else if(s1[2] == 'B'|| s2[2] == 'B')cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
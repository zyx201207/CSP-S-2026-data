#include <bits/stdc++.h>
using namespace std;
bool check_p(string s1,string s2){
	if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))return true;
	else return false;
}
bool check_xl(string s1,string s2){
	if(s1>s2)swap(s1,s2);
	if(s1[2]=='A'&&s2[2]=='B')return true;
	if(s1[2]=='B'&&s2[2]=='C')return true;
	if(s1[2]=='D'&&s2[2]=='F')return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << "1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout << "1";
			if(check_p(s1,s2)){
				cout << "1";
				if(check_xl(s1,s2))cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int k1, k2;
//判断是否在同一排 
bool check(string s1, string s2){
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C') return true;
	else if(s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C') return true;
	else if(s1[2]=='C'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B') return true;
	else if(s1[2]=='D'&&s2[2]=='E'||s1[2]=='E'&&s2[2]=='D') return true;
	else return false;
}
//判断是否相邻 
bool check2(string s1, string s2){
	if(s1[2]=='A'&&s2[2]=='B') return true;
	else if(s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C') return true;
	else if(s1[2]=='C'&&s2[2]=='B') return true;
	else if(s1[2]=='D'&&s2[2]=='E'||s1[2]=='E'&&s2[2]=='D') return true;
	else return false;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2) cout << "0000";
	else{
		cout << 1;
		string str1=s1.substr(0, 2), str2=s2.substr(0, 2);
		//将第一个座位号转数字 
		if(str1[0]=='0') k1=(int)str1[1]-'0';
		else{
			for(int i=0; i<=1; i++){
				k1=k1*10+(int)(str1[i]-'0');
			}
		}
		//将第二个座位号转数字 
		if(str2[0]=='0') k2=(int)str2[1]-'0';
		else {
			for(int i=0; i<=1; i++){
				k2=k2*10+(int)(str2[i]-'0');
			}
		}
		if(k1==k2){
			cout << 1;
			if(check(s1, s2)){
				cout << 1;
				if(check2(s1, s2)){
					cout << 1;
				}
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	} 
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
string s1 = "ABC";
string s2 = "DF";
bool f1(){
	return a1 == b1;
}
bool f2(){
	if(!f1())return false;
	return a2.substr(0,2) == b2.substr(0,2);
}
bool f3(){
	if(!f2())return false;
	if(s1.find(a2[2]) != string::npos && s1.find(b2[2]) != string::npos)return true;
	if(s2.find(a2[2]) != string::npos && s2.find(b2[2]) != string::npos)return true;
	return false;
}
bool f4(){
	if(!f3())return false;
	if(a2[2] + 1 == b2[2])return true;
	if(a2[2] == b2[2] + 1)return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> a1 >> a2 >> b1 >> b2;
	cout << f1();
	cout << f2();
	cout << f3();
	cout << f4();
	return 0;
}

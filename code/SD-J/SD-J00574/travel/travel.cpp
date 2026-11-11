#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4; 
bool flag=false,flag1=false,flag2=false;
bool cmp(string n,string m){
	if ((n[2]=='A'&&m[2]=='B')||(n[2]=='B'&&m[2]=='C')||(n[2]=='A'&&m[2]=='C')||(n[2]=='F'&&m[2]=='D')){
		return true;
	}
	if ((m[2]=='A'&&n[2]=='B')||(m[2]=='B'&&n[2]=='C')||(m[2]=='A'&&n[2]=='C')||(m[2]=='F'&&n[2]=='D')){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1==s3){
		cout << 1;
		flag=true;
	}else cout << 0;
	if (s2[0]==s4[0]&&s2[1]==s4[1]&&flag==true){
		cout << 1;
		flag1=true;
	}else cout << 0;
	if (flag1==true&&cmp(s2,s4)){
		cout << 1;
		flag2=true;
	}else cout << 0;
	if (flag2==true&&((s4[2]=='A'&&s2[2]=='B')||(s4[2]=='B'&&s2[2]=='C')||(s4[2]=='D'&&s2[2]=='F')||(s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='D'&&s4[2]=='F'))){
		cout << 1;
	}else cout << 0;
} 

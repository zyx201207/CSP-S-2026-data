//SN-J00745 陈思翰 西安辅轮中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << "1";
	}
	else{
		cout << "0";
	}
	//cout<<s1 << " " << s2;
	char d1[2]; d1[0]=s1[0]; d1[1]=s1[1];
	char a1[2]; a1[0]=s1[0]; a1[1]=s1[1];
	char b1[2]; b1[0]=s2[0]; b1[1]=s2[1];
	if(a1[0]==b1[0]&&a1[1]==b1[1]&&c1==c2)
		cout << "1";
	else{
	 	cout << "0";
	}
	if((a1[0]==b1[0]&&a1[1]==b1[1])&&(c1==c2)&&((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='C'||s2[2]=='A'))||(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D'))){ 
		cout << "1";
	}
	else
		cout << "0";
	if((a1[0]==b1[0]&&a1[1]==b1[1])&&(c1==c2)&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='C'||s2[2]=='A'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D'))){
		cout << "1";
	}
	else
		cout << "0";
	return 0;
}

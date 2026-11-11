#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s3==s1){
		cout<<"1";
		string s5=s2.substr(0,2);
		string s6=s4.substr(0,2);
		if(s5==s6){
			cout<<"1";
			if(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C'||s2[2]=='D'&&s4[2]=='F'||s2[2]=='F'&&s4[2]=='D'){
				cout<<"1";
				if(s2[2]=='A'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='A'||s2[2]=='C'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='C'||s2[2]=='D'&&s4[2]=='F'||s2[2]=='F'&&s4[2]=='D'){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

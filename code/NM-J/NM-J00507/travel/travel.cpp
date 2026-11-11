#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	int c1,c2;
	char s1[4]= {},s2[4]= {};
	cin>>c1;
	for(int i=0; i<3; i++) {
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0; i<3; i++) {
		cin>>s2[i];
	}
	if(c1==c2) {
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int x=(s1[0]-'0')*10+(s1[1]-'0');
	int y=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2&&x==y) {
		cout<<"1";
	} else {
		cout<<"0";
	}
	if(c1==c2&&x==y){
		if((s1[2]!='C'&&s2[2]!='D')&&(s1[2]!='D'&&s2[2]!='C')){
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')||(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')||(s2[2]=='D'||s2[2]=='F'))){
				cout<<"1";
			} else {
				cout<<"0";
			}
		}else{
			cout<<"0";
		}

	}else{
		cout<<"0";
	}
	if(c1==c2&&x==y){
		if(c1==c2&&x==y&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))) {
			cout<<"1";
		} else {
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	return 0;
}

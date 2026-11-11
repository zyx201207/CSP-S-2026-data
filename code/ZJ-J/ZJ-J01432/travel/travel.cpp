#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2)cout<<"1";
	else{cout<<"0000";return 0;}
	int l1 = 0,l2 = 0;
	l1 = (s1[0]-'0')*10+s1[1]-'0';
	l2 = (s2[0]-'0')*10+s2[1]-'0';
	if(l1 == l2)cout<<"1";
	else{cout<<"000";return 0;}
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
		if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
			cout<<"1";
			if(abs((s1[2]-'A') - (s2[2]-'A')) == 1)cout<<"1";
			else{cout<<"0";return 0;}
		}
		else{
			cout<<"00";return 0;
		}
	}
	else{
		if(s2[2] == 'D' || s2[2] == 'F'){cout<<"11";return 0;}
		else{cout<<"00";return 0;}
	}
	
	
	return 0;
}

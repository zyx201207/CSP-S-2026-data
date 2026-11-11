#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else if(c1==c2){
		cout<<"1";
		if(s1[0]!=s2[0] || s1[1]!=s2[1]){
			cout<<"000";
		}
		else{
			cout<<"1";
			if((char(s1[2])>='A'&&char(s1[2])<='C' && char(s2[2])>='A'&&char(s1[2])<='C')){
				cout<<"1";
				if((char(s1[2])=='A'&&char(s1[2])=='B')||(char(s1[2])=='B'&&char(s1[2])=='A')||(char(s1[2])=='B'&&char(s1[2])=='C')||(char(s1[2])=='C'&&char(s1[2])=='B')||(char(s1[2])=='C'&&char(s1[2])=='A')||char(s1[2])=='A'&&char(s1[2])=='C'){
					cout<<"1";
				}
				else cout<<"0";
			}
			else if((char(s1[2])=='D'||char(s1[2])=='F') && (char(s2[2])=='D'||char(s1[2])=='F')){
				cout<<"11";
			}
			else cout<<"00";
		}
	}
	return 0; 
}

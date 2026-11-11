#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	char s1c=s1[2];
	char s2c=s2[2];
	s1.erase(2);
	s2.erase(2);
	if(s1!=s2){
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	if((s1c<='C'&&s2c>'C')||(s2c<='C'&&s1c>'C')){
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	if(abs(int(s1c-s2c))!=1){
		cout<<"0";
	}
	else cout<<"1";
	return 0;
}

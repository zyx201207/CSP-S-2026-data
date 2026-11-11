#include<bits/stdc++.h>
using namespace std;
int c[3],a31,b31,c31,d31;
string s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s>>c[2]>>t;
	a31=(s[0]-'0')*10+(s[1]-'0');
	b31=(t[0]-'0')*10+(t[1]-'0');
	c31=s[2]-'A';
	d31=t[2]-'A';
	if(c[1]!=c[2]){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(a31!=b31){
			cout<<"000";
			return 0;
		} 
		else{
			cout<<"1";
			if(!((c31>=3&&d31>=3)||(c31<3&&d31<3))){
				cout<<"00";
				return 0;
			}
			else{
				cout<<"1";
				if(abs(c31-d31)!=1){
					cout<<"0";
				}
				else{
					cout<<"1";
				}
			}
		} 
	}
	return 0;
}

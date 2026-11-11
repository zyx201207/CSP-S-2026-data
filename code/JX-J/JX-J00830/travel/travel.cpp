#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1a,s1b,s1c,s2a,s2b,s2c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1a>>s1b>>s1c>>c2>>s2a>>s2b>>s2c;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(s1a=s2a&&s1b==s2b){
			cout<<"1";
			if((s1c=='D'&&s2c=='F')||(s1c=='F'&&s2c=='D')||((s1c=='A'||s1c=='B'||s1c=='C')&&(s2c=='A'||s2c=='B'||s2c=='C'))){
				cout<<"1";
				if((s1c=='D'&&s2c=='F')||(s1c=='F'&&s2c=='D')||((s1c=='A'||s1c=='A')&&(s1c=='B'||s2c=='B'))||((s1c=='B'||s1c=='B')&&(s1c=='C'||s2c=='C'))){
					cout<<"1";
					return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
string a,b;
string s,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>r;
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<"1";
		if((s[0]-'0'==r[0]-'0')&&(s[1]-'0'==r[1]-'0')){
			cout<<"1";
			if(((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(r[2]=='A'||r[2]=='B'||r[2]=='C'))||((s[2]=='D'||s[2]=='F')&&(r[2]=='D'||r[2]=='F'))){
				cout<<"1";
				if((s[2]=='C'&&r[2]=='A')||(s[2]=='A'&&r[2]=='C')){
					cout<<"0";
					return 0;
				}
				else{
					cout<<"1";
				}
			}
			else{
				cout<<"00";
			}
		}
		else {
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 

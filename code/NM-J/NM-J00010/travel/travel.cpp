#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,cl;
	string s,sl;
	cin>>c>>s;
	cin>>cl>>sl;
	if(c==cl){
		cout<<"1";
		if(s[0]==sl[0]&&sl[1]==s[1]){
			cout<<"1";
			if(s[2]=='F'&&sl[2]=='D'||s[2]=='A'&&sl[2]=='B'||s[2]=='A'&&sl[2]=='C'||s[2]=='B'&&sl[2]=='C'||s[2]=='D'&&sl[2]=='F'||s[2]=='B'&&sl[2]=='A'||s[2]=='C'&&sl[2]=='A'||s[2]=='C'&&sl[2]=='B'){
				cout<<"1";
				if((int)s[2]-(int)sl[2]==1||(int)s[2]-(int)sl[2]==-1){
					cout<<"1"; 
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	} 
	return 0;
}

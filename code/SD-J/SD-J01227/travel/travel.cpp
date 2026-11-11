#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s[6];
	cin>>c1>>s[0]>>s[1]>>s[2]>>c2>>s[3]>>s[4]>>s[5];
	if(c1==c2){
		cout<<"1";
		if(s[0]==s[3]&&s[1]==s[4]){
			cout<<"1";
			if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
				if(s[5]=='A'||s[5]=='B'||s[5]=='C'){
					cout<<"1";
					if(s[2]-s[5]==1||s[5]-s[2]==1)
						cout<<"1";
					else cout<<"0";
				}
				else cout<<"00";
			}
			else if(s[2]=='D'||s[2]=='F'){
				if(s[5]=='D'||s[5]=='F')
					cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

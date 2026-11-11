#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	cin>>c1>>c2;
	cin>>s1>>s2;
	int b=0;
	if(c1==s1){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s2[1]!=c2[1]){
		cout<<"000";
		return 0;
	}
	else{
		cout<<'1';
	}
	if((s2[2]=='c'||s2[2]=='B'||s2[2]=='A')&&(c2[2]=='C'||c2[2]=='B'||c2[2]=='A')){	
			cout<<'1';
			for(int i=0;i<c2.size();i++){
				if((c2[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&c2[2]=='B')||(c2[2]=='B'&&s2[2]=='C')||(c2[2]=='C'&&s2[2]=='B')){
					cout<<'1';
					return 0;
				}
				else{
					cout<<'0';
					return 0;
				}
			}
		}
	else{
		cout<<"00";
		return 0;
	}
	if((s2[2]=='D'||s2[2]=='F')&&(c2[2]=='D'||c2[2]=='F')){
		cout<<"11";
		return 0;
	}
	return 0;
}

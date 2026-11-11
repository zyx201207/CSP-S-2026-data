#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
		cout<<1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			cout<<1;
			if(s2[2]=='A'&&s4[2]=='B'||s2[2]=='A'&&s4[2]=='C'||s2[2]=='B'&&s4[2]=='A'||s2[2]=='B'&&s4[2]=='C'||s2[2]=='C'&&s4[2]=='A'||s2[2]=='C'&&s4[2]=='B'){
				cout<<1;
				if(s2[2]+1==s4[2]||s2[2]-1==s4[2]){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(s2[2]=='D'&&s4[2]=='F'||s2[2]=='F'&&s4[2]=='D'){
				cout<<11;
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

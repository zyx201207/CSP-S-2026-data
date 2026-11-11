#include<iostream>
#include<cstring>
using namespace std;
string s,s1;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>s1;
	if(a==b){
		cout<<1;
		if(s[1]==s1[1]&&s1[0]==s[0]){
			cout<<1;
			if((s[2]!='F'||s[2]!='D')&&(s1[2]!='F'||s1[2]!='D')||(s[2]=='F'||s[2]=='D')&&(s1[2]=='F'||s1[2]=='D')){
				cout<<1;
				if((s[2]=='B'&&(s1[2]=='A'||s1[2]=='C'))||(s1[2]=='B'&&(s[2]=='A'||s[2]=='C'))||((s[2]=='D'||s[2]=='F')&&(s1[2]=='D'||s1[2]=='F'))){
					cout<<1;
				}else cout<<0;
			}else cout<<00;
		}else cout<<000; 
	}else cout<<0000;
	return 0;
} 

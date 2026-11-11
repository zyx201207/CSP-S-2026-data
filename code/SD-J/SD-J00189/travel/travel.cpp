#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c,s,c1,s1;
	cin>>c>>s>>c1>>s1;
	bool a=0,b=0,d=0,e=0;
	if((c=="01"||c=="16")||(c1=="01"||s1=="16")){
		cout<<"0000";
	}
	if(c==c1){
		a=1;
		if(s[0]==s1[0]&&s[1]==s1[1]){
			b=1;	
		}
		else{
			cout<<"1000";
			return 0;
		}
		if(b==1){
			if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s[2]!=s1[2])){
				d=1;
				if(s[2]=='A'&&s1[2]=='B'){
					e=1;
				}
				else if(s[2]=='C'&&s1[2]=='B'){
					e=1;
				}
				else if(s[2]=='B'&&(s1[2]=='A'||s1[2]=='C')){
					e=1;
				}
			}
			else if((s[2]=='D'||s[2]=='F')&&(s1[2]=='D'||s1[2]=='F')&&(s[2]!=s1[2])){
				d=1;
				e=1;
			}
		}
	}
	cout<<a<<b<<d<<e;
	return 0;
} 

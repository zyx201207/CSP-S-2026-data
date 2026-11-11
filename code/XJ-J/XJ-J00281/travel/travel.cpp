#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	bool a=0,b=0,c=0,d=0;
	cin>>s1>>s3>>s2>>s4;
	if((s1==s2)&&(s1[0]=='0'&&s1[1]=='2')){
		a=1;
		if(s3[0]==s4[0]&&s3[1]==s4[1]){
			b=1;
			if((s3[2]>='A'&&s3[2]<='C')&&(s4[2]>='A'&&s4[2]<='C')){
				c=1;
				if(s3[2]=='A'&&s4[2]=='B'){
					d=1;
				}else if(s3[2]=='B'&&(s4[2]=='A'||s4[2]=='C')){
					d=1;
				}else if(s3[2]=='C'&&s4[2]=='B'){
					d=1;
				}
			}else if((s3[2]=='D'||s3[2]=='F')&&(s4[2]=='D'||s4[2]=='F')){
				c=1;
				d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
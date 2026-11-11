#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s2[0]==s4[0]&&s2[1]==s4[1]){
		cout<<1;
	}
	else {
		cout<<"000";
		return 0;
	}
	int a,b;
	if(s2[2]<='C')a=s2[2]-'A';
	else if(s2[2]=='D')a=3;
	else if(s2[2]=='E')a=4;
	if(s4[2]<='C')b=s4[2]-'A';
	else if(s4[2]=='D')b=3;
	else if(s4[2]=='E')b=4;
	if((a<=2&&b<=2)||(a>2&&b>2))cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	if(abs(a-b)==1)cout<<"1";
	else cout<<"0";
	return 0;
} 

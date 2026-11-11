#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int pd(char c){
	if(c=='A'||c=='B'||c=='C')return 1;
	else return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<"1";
	else cout<<"0";
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1])cout<<"1";
	else cout<<"0";
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]&&pd(s2[2])==pd(s4[2]))cout<<"1";
	else cout<<"0";
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]&&pd(s2[2])==pd(s4[2])&&(abs(s4[2]-s2[2])==1||s2[2]=='D'&&s4[2]=='F'||s2[2]=='F'&&s4[2]=='D'))cout<<"1";
	else cout<<"0";
	return 0;
}

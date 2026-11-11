#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,s="0000";
	cin>>c1>>s1>>c2>>s2;
	if((c1[0]=='0'&&c1[1]=='1') || (c1[0]=='1'&&c1[1]=='6')){
		return 0;
	}
	if((c2[0]=='0'&&c2[1]=='1') || (c2[0]=='1'&&c2[1]=='6')){
		return 0;
	}
	if(c1[0]==c2[0] && c1[1]==c1[1]){
		s[0]='1';
	}
	if(s[0]=='1' && s2[0]==s2[0] && s2[1]==s2[1]){
		s[1]='1';
	}
	if(s[1]=='1' && (s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		s[2]='1';
	}
	if(s[1]=='1' && (s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		s[2]='1';
	}
	int n=(int(s1[2])-int(s2[2]))*-1;
	int m1=(int(s1[0]-'0'))*10+(int(s1[1]-'0'));
	int m2=(int(s2[0]-'0'))*10+(int(s2[1]-'0'));
	int l=(m1-m2)*-1;
	if(s[2]=='1' && (n==1 || l==1)){
		 s[3]='1';
	}
	cout<<s;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
string j;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)j[0]='1';
	else{
		j[0]='0';
		j[1]='0';
		j[2]='0';
		j[3]='0';
		cout<<j[0]<<j[1]<<j[2]<<j[3];
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])j[1]='1';
	else{
		j[1]='0';
		j[2]='0';
		j[3]='0';
		cout<<j[0]<<j[1]<<j[2]<<j[3];
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))j[2]='1';
	else{
		j[2]='0';
		j[3]='0';
		cout<<j[0]<<j[1]<<j[2]<<j[3];
		return 0;
	}
	int ss1=0,ss2=0;
	ss1=s1[2]-'A';
	ss2=s2[2]-'A';
	if(abs(ss1-ss2)==1)j[3]='1';
	else{
		j[3]='0';
		cout<<j[0]<<j[1]<<j[2]<<j[3];
		return 0;
	}
	cout<<j[0]<<j[1]<<j[2]<<j[3];
	return 0;
}

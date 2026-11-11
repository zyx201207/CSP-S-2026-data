#include<bits/stdc++.h>
using namespace std;
int n1,n2,c1,c2,x1,x2,x3;
string s1,s2,s0="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	c1=(s1[0]-'0')*10+(s1[1]-'0');
	c2=(s2[0]-'0')*10+(s2[1]-'0');
	x1=(s1[2]-'A'+1);
	x2=(s2[2]-'A'+1);
	if(x2==6)x2=5;
	if(x1>=x2)x3=x1-x2;
	else{x3=x2-x1;}
	if(n1==n2)s0[0]='1';
	if(s0[0]=='1'&&c1==c2)s0[1]='1';
	if(s0[1]=='1'&&((x1<=3&&x2<=3)||(x1>=4&&x2>=4)))s0[2]='1';
	if(s0[2]=='1'&&x3==1)s0[3]='1';
	cout<<s0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

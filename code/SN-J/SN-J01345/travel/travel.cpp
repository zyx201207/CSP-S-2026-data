//QJYZ SN-J01345 YangJunnan
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2; 
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) {cout<<1;}
	else {cout<<"0000";return 0;}
	
	int flag=0;
	for(int i=0;i<=1;i++)
	{
		if(s1[i]==s2[i]) {flag++;}
		else			{break;}
	}
	if(flag<2) {cout<<"000";return 0;}
	else if(flag==2) {cout<<1;}
	
	if((s1[2]!='D'&&s1[2]!='F')&&(s2[2]!='D'&&s2[2]!='F')) {cout<<1;}
	else if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')) {cout<<"11";return 0;}
	else {cout<<"00";return 0;}
	
	char l1=s1[2],l2=s2[2];
	if(l1=='B'||l2=='B') {cout<<1;}
	else {cout<<0;}
	
	return 0;
}

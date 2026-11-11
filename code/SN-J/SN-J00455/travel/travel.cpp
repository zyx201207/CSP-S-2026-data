#include<bits/stdc++.h>
using namespace std;
//SN-J00455 zhaoweize

bool flag1=1;//tongpai
bool flag2,flag3,flag4;
string c1,s1,c2,s2;

int main()
{	

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	for(int i=0;i<=1;i++)
	{
		if(s1[i]!=s2[i])flag1=0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')flag2=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')flag3=1;
	if(s1[2]=='D'||s1[2]=='F')flag2=0;
	if(s2[2]=='D'||s2[2]=='F')flag3=0;
	if(abs(s1[2]-s2[2])==1)flag4=1;
	else flag4=0;
	
	if(c1==c2)cout<<1;//tongche
	else cout<<0;
	if(c1==c2&&flag1)cout<<1;//tongchetongpai
	else cout<<0;
	if(c1==c2&&flag1&&flag2==flag3)cout<<1;//tongce
	else cout<<0;
	if(c1==c2&&flag1&&flag2==flag3&&flag4)cout<<1;
	else cout<<0;//xianglin
	
	
	
	
	return 0;
}

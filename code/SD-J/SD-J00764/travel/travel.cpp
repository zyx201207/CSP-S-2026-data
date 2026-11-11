#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool zhuang[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)zhuang[1]=true;
	if(c1!=c2)
	{
		zhuang[1]=false,zhuang[2]=false,zhuang[3]=false,zhuang[4]=false;
		for(int i=1;i<=4;i++)cout<<zhuang[i];
		return 0;
	}
	int pei1=(s1[0]-'0')*10+(s1[1]-'0'),pei2=(s2[0]-'0')*10+(s2[1]-'0');
	if(pei1==pei2)zhuang[2]=true;
	if(pei1!=pei2)
	{
		zhuang[2]=false,zhuang[3]=false,zhuang[4]=false;
		for(int i=1;i<=4;i++)cout<<zhuang[i];
		return 0;
	}
	int shu1=0,shu2=0;
	if((s1[2]=='A'||s1[2]=='B')||s1[2]=='C')shu1=1;
	if((s2[2]=='A'||s2[2]=='B')||s2[2]=='C')shu2=1;
	if(s1[2]=='D'||s1[2]=='F')shu1=2;
	if(s2[2]=='D'||s2[2]=='F')shu2=2;
	if(shu1==shu2)
	{
		zhuang[3]=true;
		if(shu1==2)zhuang[4]=true;
		else if(shu1==1)
		{
			int cha=0,s11=s1[2]-'0',s22=s2[2]-'0';
			cha=abs(s11-s22);
			if(cha==1)zhuang[4]=true;
			else zhuang[4]=false;
		}
	}
	else if(shu1!=shu2)zhuang[3]=false,zhuang[4]=false;
	for(int i=1;i<=4;i++)cout<<zhuang[i];
	return 0;
}

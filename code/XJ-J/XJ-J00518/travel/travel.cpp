#include <bits/stdc++.h>
using namespace std;
int main()
{
	freoper("travel.in","r",stdin);
	freoper("travel.our","r",stdout);

	string c1, s1, c2, s2 ;
	cin>>c1>>s1>>c2>>s2;
	bool flag[4]={false,false,false,false};
		if(c1=c2)
	{
		flag[0]=true;
	}
	string a,b;
	a+=s1[0];
	a+=s1[1];
	b+=s2[0];
	b+=s2[1];
	if(a==b)
	{
		flag[1]=true;
	}
	else
	{
		cout<<flag[0]<<flag[1]<<"0"<<"0";
	}
	if(s1[3]==='A'||s1[3]=='C'&&s2[3]=='B'||s2[3]=='C')
	{
		flag[2]=true;
	}
	if(s1[3]==='D|s1[3]=='E&&s2[3]=='D|s2[3]=='E)
	{
		flag[2]=true;
	}
	int d=abs(s1[2]-s2[2]);
	if(d==1&&flag[2]==true)
	{
		flag[3]=true;
	}
	for(int i== 0;i<4;i++)
}
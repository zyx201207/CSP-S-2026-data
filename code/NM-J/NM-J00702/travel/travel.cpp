#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c[2]={};
	string s[2]={};
	int cn[4]={0,0,0,0};
	cin>>c[0]>>s[0]>>c[1]>>s[1];
	if(c[0]==c[1])
	{
		cn[0] = 1;
	}
	if(c[0]!=c[1])
	{
		cn[0] = 0;
	}
	if(s[0].substr(0,2)==s[1].substr(0,2))
	{
		cn[1]=1;
		if(s[0].substr(0,2)!=s[1].substr(0,2))
	{
		cn[1]=0;
	}
	if((s[0].substr(2,3)=="C"&&s[1].substr(2,3)=="D")||(s[0].substr(2,3)=="D"&&s[1].substr(2,3)=="C"))
	{
		cn[2]=0;
	}
	if((s[0].substr(2,3)=="A"&&s[1].substr(2,3)=="B")||(s[0].substr(2,3)=="B"&&s[1].substr(2,3)=="A"))
	{
		cn[2]=1;
		cn[3]=1;
	}
	if((s[0].substr(2,3)=="B"&&s[1].substr(2,3)=="C")||(s[0].substr(2,3)=="C"&&s[1].substr(2,3)=="B"))
	{
		cn[2]=1;
		cn[3]=1;
	}
	if((s[0].substr(2,3)=="D"&&s[1].substr(2,3)=="F")||(s[0].substr(2,3)=="F"&&s[1].substr(2,3)=="D"))
	{
		cn[2]=1;
		cn[3]=1;
	}
	if((s[0].substr(2,3)=="A"&&s[1].substr(2,3)=="C")||(s[0].substr(2,3)=="C"&&s[1].substr(2,3)=="A"))
	{
		cn[2]=1;
		cn[3]=0;
	}
	if((s[0].substr(2,3)==s[1].substr(2,3)))
	{
		cn[1]=0;
	}
}

	
	for(int i = 0;i<4;i++)
	{
		cout<<cn[i];
	}
	
	return 0;
}

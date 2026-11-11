#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
char ch1[4],ch2[4];
int f,f2,fl,fl2,f3;

int cnt;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans+="1";
		f=1;
	}
	else
	{
		ans+="0";
	}
	for(int i=0;i<s1.size();i++)
	{
		ch1[i]=s1[i];
		ch2[i]=s2[i];
		if(s1[i]==s2[i])
		{
			cnt++;
		}
	}
	if(cnt>=2&&f==1)
	{
		ans+="1";
		f2=1;
	}
	else
	{
		ans+="0";
	}
	if(ch1[2]>='A'&&ch1[2]<='C')
	{
		fl=1;
	}
	if(ch1[2]>='D'&&ch1[2]<='F')
	{
		fl=0;
	}
	if(ch2[2]>='A'&&ch2[2]<='C')
	{
		fl2=1;
	}
	if(ch2[2]>='D'&&ch2[2]<='F')
	{
		fl2=0;
	}
	if(f2==1&&fl==fl2)
	{
		ans+="1";
		f3=1;	
	}
	else
	{
		ans+="0";
	}
	if(f3==1)
	{
		if(ch1[2]+1-'A'==ch2[2]-'A'||ch1[2]-1-'A'==ch2[2]-'A')
		{
			ans+="1";
		}
	}
	else
	{
		ans+="0";
	}
	cout<<ans;
	return 0;
 } 

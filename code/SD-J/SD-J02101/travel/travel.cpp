#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("D:\\SD-J02101ÁõĞ¢ìÍ\\travel\\travel.in\\travel.in","r",stdin);
	freopen("D:\\SD-J02101ÁõĞ¢ìÍ\\travel\\travel.out\\travel.ans","w",stdout);
	int a=0,b=0,c=0;
	string c1,s1,c2,s2;
	for(int i=0;i<2;i++) cin>>c1[i];
	for(int i=0;i<3;i++) cin>>s1[i];
	for(int i=0;i<2;i++) cin>>c2[i];
	for(int i=0;i<3;i++) cin>>s2[i];
	for(int i=0;i<2;i++) 
	{
		if(c1[i]==c2[i])
		{
			a++;
		}
		else
		{
			cout<<"0000";
			return 0;
		}
		if(a==2)
		{
			cout<<1;
			a=0;
			break;
		}
	}
	for(int i=0;i<2;i++)
	{
		if(s1[i]==s2[i]) 
		{
			a++;
		}
		else
		{
			cout<<"000";
			return 0;
		}
		if(a==2)
		{
			cout<<1;
			break;
		}
	}
	b=s1[2]-'0';
	c=s2[2]-'0';
	if((b+c)<=('A'+'C'))
	{
		cout<<1;
	}
	else if((b+c)==('D'+'F'))
	{
		cout<<11;
		return 0;
	}
	else
	{
		cout<<00;
		return 0;
	}
	if((b-c)==1 || (b-c)==-1)
	{
		cout<<1;
		return 0;
	}
	else
	{
		cout<<0;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//11 13D 12 15F







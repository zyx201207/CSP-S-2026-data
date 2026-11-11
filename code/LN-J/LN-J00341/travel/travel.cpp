#include<bits/stdc++.h>
using namespace std;
char s1[5];
char s2[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
	   cout<<'1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1])
	{
		cout<<'1';
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((s1[2]<=67&&s2[2]<=67)||(s2[2]>67&&s1[2]>67))
	{
		cout<<'1';
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(s1[2]-1==s2[2]||s1[2]+1==s2[2])
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
   return 0;	
}

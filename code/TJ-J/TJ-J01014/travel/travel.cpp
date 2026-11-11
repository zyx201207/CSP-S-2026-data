#include<bits/stdc++.h> 
using namespace std;
string z_1,z_2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c_1,c_2;
	string s_1,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	int len=s_1.size();
	for(int i=0;i<len;i++)
	{
		if(s_1[i]>='0'&&s_1[i]<='9')
		{
			z_1=z_1+s_1[i];
		}
	}
	for(int i=0;i<len;i++)
	{
		if(s_2[i]>='0'&&s_2[i]<='9')
		{
			z_2=z_2+s_2[i];
		}
	}
	if(z_1!=z_2)
	{
		cout<<"000";
		return 0;
	}
	else
	{
		cout<<"1"; 
		if(s_1[len-1]=='C'&&s_2[len-1]=='D')
		{
			cout<<"00";
			return 0;
		}
		else
		{
			cout<<"1" ;
			if(abs((s_1[len-1]-'A')-(s_2[len-1]-'A'))==1)
			{
				cout<<"1";
				return 0;
			}
			else
			{
				cout<<"0";
				return 0;
			}
		}
	}
	return 0; 
}

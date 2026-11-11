#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool flag=1;
	for(int i=0;i<c1.size();i++)
	{
		if(c1[i]!=c2[i])
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		cout<<"1";
		flag=1;
		for(int i=0;i<s1.size()-1;i++)
		{
			if(s1[i]!=s2[i])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"1";
			flag=1;
			char ch1=s1[2],ch2=s2[2];
			if(ch1<='F'&&ch1>='D'&&ch2<='F'&&ch2>='D')
			{
				cout<<"11";
			}
			else if(ch1<='C'&&ch1>='A'&&ch2<='C'&&ch2>='A')
			{
				cout<<"1";
				if(abs(ch1-ch2)==1)
				{
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

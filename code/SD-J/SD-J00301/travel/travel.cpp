#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	int len=b1.size();
	int zhi1=b1[len-1]-'A';
	int zhi2=b2[len-1]-'A';
	if(a1==a2)
	{
		cout<<'1';
		for(int i=0;i<len-1;i++)
		{
			if(b1[i]!=b2[i])
			{
				cout<<"000";
				return 0;
			}
		}
		cout<<'1';
		if(b1[len-1]=='A'&&b2[len-1]=='B'||b1[len-1]=='A'&&b2[len-1]=='C'||b1[len-1]=='B'&&b2[len-1]=='A'||b1[len-1]=='B'&&b2[len-1]=='C'||b1[len-1]=='C'&&b2[len-1]=='B'||b1[len-1]=='C'&&b2[len-1]=='A'||b1[len-1]=='F'&&b2[len-1]=='D'||b1[len-1]=='D'&&b2[len-1]=='F')
		{
			cout<<'1';
		}
		else
		{
			cout<<"00";
			return 0;
		}
		if(zhi1==(zhi2-1)||zhi1==(zhi2+1))
		{
			cout<<'1';
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}

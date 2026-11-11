#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	if(s!=s2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<1;
	}
	int a=s1[0]+s1[1],b=s3[0]+s3[1];
	if(a!=b)
	{
		cout<<"000";
		return 0;
	}
	else
	{
		cout<<1;
	}
	int c=s1[2],d=s3[2];
	if(((c!='F')&&(c!='D')&&(d!='F')&&(d!='D'))||((c=='F')||(c=='D')&&(d=='F')||(d=='D')))
	{
		cout<<1;
		if((c-d==1||c-d==-1)||(c=='F')||(c=='D'))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		cout<<"00";
		return 0;
	}
	return 0;
}

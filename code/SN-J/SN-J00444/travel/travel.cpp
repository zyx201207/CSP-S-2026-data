#include<bits/stdc++.h>
using namespace std;
bool check1(char a,char b)
{
	return a>='A'&&a<='C'&&b>='A'&&b<='C'||a>='D'&&a<='E'&&b>='D'&&b<='E';
}
bool check2(char a,char b)
{
	return max(a,b)-min(a,b)==1&&min(a,b)!='C'&&max(a,b)!='D';
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		cout<<"1";
		if(s2[0]==s4[0]&&s2[1]==s4[1]) 
		{
			cout<<"1";
			if(check1(s2[2],s4[2]))
			{
				cout<<"1";
				if(check2(s2[2],s4[2]))
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
	return 0;
} 

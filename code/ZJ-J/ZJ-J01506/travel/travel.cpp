#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	string s;
	int c1,c2;
	int c3,c4;
	string s1,s2;
	int s3,s4;
	cin>>c1>>s1>>c2>>s2;
	c3=(s1[0]-'0')*10+s1[1]-'0';
	c4=(s2[0]-'0')*10+s2[1]-'0';
	s3=s1[2]-'A';
	s4=s2[2]-'A';
	bool a1=0,a2=0,a3=0,a4=0;
	if(c1==c2) a1=1;
	if(a1)
	{
		if(c3==c4) a2=1;
		if(a2)
		{
			if((s3<=2&&s4<=2)||(s3>=3&&s4>=3))
			{
				a3=1;
			}
			if(a3&&(s3-s4==-1||s3-s4==1)) a4=1;
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
} 

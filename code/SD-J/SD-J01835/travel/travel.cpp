#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s;
int a=0;
char t;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
	{
		s+="1";
		for(int i = 0;i <= 1;i++)
		{
			if(s1[i]==s2[i])
			{
				a=1;
			}
			else
			{
				a=0;
			}
		}
		if(a)
		{
			s+="1";
			char a=s1[2],b=s2[2];
			if(a>b)
			{
				t=b;
				b=a;
				a=t;
			}
			if(a>='A'&&a<='C'&&b>='A'&&b<='C'&&a!=b||a>='D'&&a<='E'&&b>='D'&&b<='E'&&a!=b)
			{
				s+="1";
				a+=1;
				if(a==b)s+="1";
				else s+="0";
			}
			else
			{
				s+="00";
			}
		}
		else s+="000";
	}
	else
	{
		s+="0000";
	}
	cout << s;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int x1=0;
int x2=0;
int x3=0;
int x4=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		x1=1;
		if(s2[0]==s4[0] && s2[1]==s4[1])
		{
			x2=1;
			if((s2[2]>='A' && s2[2]<='C' && s4[2]>='A' && s4[2]<='C') || (s2[2]>='D' && s2[2]<='E' && s4[2]>='D' && s4[2]<='E'))
			{
				x3=1;
				int m=abs(int(s2[2])-int(s4[2]));
				if(m==1)
				{
					x4=1;
				}
			}
		}
	}
	cout<<x1<<x2<<x3<<x4;
	return 0;
}

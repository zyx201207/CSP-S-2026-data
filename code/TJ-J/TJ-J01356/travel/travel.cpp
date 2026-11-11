#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],s1[3],c2[2],s2[3];
	cin>>c1>>s1>>c2>>s2;
	int a[4]={0};
	int b,c;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
		b=1;
	else
		b=2;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		c=1;
	else
		c=2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		a[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			a[1]=1;
			if(b==c)
			{
				a[2]=1;
				if(b==1)
				{
					if(s1[2]=='A'&&s2[2]=='B')
					    a[3]=1;
					if(s1[2]=='B'&&s2[2]=='C')
				        a[3]=1;
				    if(s2[2]=='A'&&s1[2]=='B')
					    a[3]=1;
					if(s2[2]=='B'&&s1[2]=='C')
				        a[3]=1;
				}
				else
				{
					a[3]=1;
				}
			}
		}
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}


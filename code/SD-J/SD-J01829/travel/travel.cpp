#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char id1=s1[2],id2=s2[2];
	int n1=0,n2=0,n3=0,n4=0;
	if(c1==c2)
	{
		n1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			n2=1;
			if((id1>='A'&&id1<='C'&&id2>='A'&&id2<='C')||(id1>='D'&&id1<='F'&&id2>='D'&&id2<='F'))
			{
				n3=1;
				if(abs(id1-id2)==1)
				{
					n4=1;
				}
			}
		}
	}
	printf("%d%d%d%d",n1,n2,n3,n4);
	return 0;
} 

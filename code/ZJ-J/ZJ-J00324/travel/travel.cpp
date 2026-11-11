#include<bits/stdc++.h>
using namespace std;
long long x,y,z,w;
string st1,st2;
char ch1,ch2;
int main()
{
	freopen("travel.in","r",stdin);
//	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>x>>st1>>y>>st2;
	z=(st1[0]-'0')*10+st1[1]-'0';
	w=(st2[0]-'0')*10+st2[1]-'0';
	ch1=st1[2];
	ch2=st2[2];
	if(x==y)
	{
		printf("1");
		if(z==w)
		{
			printf("1");
			if((ch1<'D'&&ch2<'D')||(ch1>'C'&&ch2>'C'))
			{
				printf("1");
				if(abs(int(ch1-ch2))==1||(ch1=='D'&&ch2=='F')||(ch2=='D'&&ch1=='F'))printf("1\n");
				else printf("0\n");
			}
			else printf("00\n");
		}
		else printf("000\n");
	}
	else printf("0000\n");
    return 0;
} 

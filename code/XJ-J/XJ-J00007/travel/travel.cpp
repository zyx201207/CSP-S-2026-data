#include<bits/stdc++.h>
using namespace std;
long long c1,c2,m1,m2,i,l,k;
char s1[10],s2[10],n1,n2;
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	n1=s1[2];
	n2=s2[2];
	m1=(s1[0]-'0')*10+(s1[1]-'0');
	m2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1<2||c2<2||c1==16||c2==16||c1>17||c2>17||m1<1||m2<1||m1>18||m2>18)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		if(c1==c2)
		{
			cout<<"1";
			if(m1==m2)
			{
				cout<<"1";
				if(n1=='A'&&n2=='B'||n1=='A'&&n2=='C'||n1=='B'&&n2=='C'||n1=='B'&&n2=='C'||n1=='C'&&n2=='A'||n1=='C'&&n2=='B'||n1=='D'&&n2=='F'||n1=='F'&&n2=='D')
				{
					cout<<"1";
					if(n1-n2==1||n2-n1==1)
					cout<<"1";
					else
					{
						cout<<"0";
						return 0;
					}
				}
				else
				{
					cout<<"00";
					return 0;
				}
			}
			else
			{
				cout<<"000";
				return 0;
			}
		}
		else
		{
			cout<<"0000";
			return 0;
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
bool flag1,flag2,flag3,flag4;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	b=' '+b;
	d=' '+d;
	if(a==c)
	{
		flag1=1;
		if(b[1]==d[1] && b[2]==d[2])
		{
			flag2=1;
			if(('A'<=b[3] && b[3]<='C' && 'A'<=d[3] && d[3]<='C') || ('D'<=b[3] && b[3]<='F' && 'D'<=d[3] && d[3]<='F'))
			{
				flag3=1;
				if((b[3]=='A' && d[3]=='B') || (b[3]=='B' && (d[3]=='C' || d[3]=='A')) || (b[3]=='C' && d[3]=='B') || (b[3]=='D' && d[3]=='F') || (b[3]=='F' || d[3]=='D'))
				{
					flag4=1;
				}
				else
				{
					flag4=0;
				}
			}
			else
			{
				flag3=0;
				flag4=0;
			}
		}
		else
		{
			flag2=0;
			flag3=0;
			flag4=0;
		}
	}
	else
	{
		flag1=0;
		flag2=0;
		flag3=0;
		flag4=0;
	}
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
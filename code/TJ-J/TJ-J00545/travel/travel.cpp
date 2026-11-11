#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>a1>>b1;
	int c,c1;
	c=int(a[1]-48);
//	cout<<c<<" ";
	c1=int(a1[1]-48);
//	cout<<c1<<" ";
	int z=int(b[0]-48)*10+int(b[1]-48);
//	cout<<z<<" ";
	int z1=int(b1[0]-48)*10+int(b1[1]-48);
//	cout<<z1<<" ";
	
	if(c==c1)
	{
		if(z==z1)
		{
			char s=b[2];
			char s1=b1[2];
//			cout<<s<<" "<<s1;
			if(((s=='A'||s=='B'||s=='C')&&(s1=='D'||s1=='F'))||((s1=='A'||s1=='B'||s1=='C')&&(s=='D'||s=='F')))
			{
				cout<<"1100";
				return 0;
			}
			else
			{
				if((s=='A'&&s1=='B')||(s=='B'&&(s1=='A'||s1=='C'))||(s=='C'&&s1=='B')||(s=='D'&&s1=='F')||(s=='F'&&s1=='D'))
				{
					cout<<"1111";
					return 0;
				}
				else
				{
					cout<<"1110";
					return 0;
				}
			}
		}
		else
		{
			cout<<"1000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int n=s1.size(),c=0,d=0,a[105],b[105];
	if(c1==c2)
	{
		cout << 1;
		for(int i=0;i<n;i++)
		{
			if(s1[i]>='0'&&s1[i]<='9')
			{
				a[++c]=s1[i]-'0';
			}
			if(s2[i]>='0'&&s2[i]<='9')
			{
				b[++d]=s2[i]-'0';
			}
		}
		if(a[1]==b[1]&&a[0]==b[0])
		{
			cout << 1;
			if(((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F'))||((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'))){
				cout << 1;
				if((s1[3]+'1'==s2[3])||(s1[3]-'1'==s2[3]))
					{
						cout << 1;
						return 0;
					}
				else
				{
					cout << 0;
					return 0;
				}
			}
			else
			{
				cout << 00;
				return 0;
			}
		}
		else
		{
			cout <<000;
			return 0;
		}
	}
	else
	{
		cout << 0000;
		return 0;
	}
 } 

#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,a,b;
	char c,v;
	s+='0';
	s+='0';
	s+='0';
	s+='0';
	scanf("%d %d %c %d %d %c",&n,&m,&c,&a,&b,&v);
	
	
	if(n==a)
	{
		s[0]='1';
		if(m==b)
		{
			s[1]='1';
			if(((c>='A'&&c<='C')&&(v>='A'&&v<='C'))||((c>='D'&&c<='F')&&(v>='D'&&v<='F')))	
			{
				s[2]='1';
				if(abs(int(c)-int(v))==1)
				{
					s[3]='1';	
				}	
			}
			
		}
	}
	cout<<s;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b; 
	string s1,c1,s2,c2,s;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		s="1000";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
		
			s="1100";
			a=int(s1[2]-'0');
			b=int(s2[2]-'0');
			if(a+1==b||a+2==b||a-1==b||a+1==b||a-2==b||a-1==b)
			{
				if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'||s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
				{
					s="1110";
					if(a+1==b||a-1==b)
					{
						s="1111";
					}	
					else s="1110";
				}	
			}
			else 
			{
				s="1100";
			}
		}
		else s="1000";
		cout<<s;
	}
	else{
		cout<<"0000";
	}
	return 0;
}
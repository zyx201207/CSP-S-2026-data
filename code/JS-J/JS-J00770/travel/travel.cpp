#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s="";
int x1,x2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		s+='1';
		x1=(s1[0]-'0')*10+s1[1]-'0';
		x2=(s2[0]-'0')*10+s2[1]-'0';
		if(x1==x2)
		{
			 s+='1';
			 int f=int(s1[2]+s2[2]);
			 if(f==int('A'+'B')||f==int('A'+'C')||f==int('B'+'C')||f==int('D'+'F'))
			 {
				 s+='1';
				 if(abs(s1[2]-s2[2])==1)
				 {
					 s+='1';
				 }
				 else s+='0';
			 }
			 else s+="00";
		}
		else
		{ 
			s+="000";
		}
	}
	else 
	{
		s+="0000";
	}

	cout<<s;
	return 0;
}

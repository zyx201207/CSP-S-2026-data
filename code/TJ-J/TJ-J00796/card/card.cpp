#include <bits/stdc++.h> 
using namespace std;

int main()
{	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	string c1,s1,c2,s2;
	string aa,bb;
	char aa1,bb1;
	bool tt1=false,tt2=false,tt3=false,tt4=false;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<3;i++)
	{
		if(s1[i]>='0' && s1[i]<='9')
		{
			aa+=s1[i];
		}else aa1=s1[i];
		if(s2[i]>='0' && s2[i]<='9')
		{
			bb+=s2[i];
		}else bb1=s2[i];
	}
	if(c1==c2)
	{
		tt1=true;
		if(aa==bb)
		{
			tt2=true;
			if((aa1<='F' && aa1>='D' && bb1<='F' && bb1>='D'))
			{
				tt3=true;
				if((aa1-bb1)==1 || (bb1-aa1)==1) tt4=true;
			}
			if((aa1<='C' && aa1>='A' && bb1<='C' && bb1>='A'))
			{ 
				tt3=true;
				if((aa1-bb1)==1 || (bb1-aa1)==1) tt4=true;
			}	
		}
	}
	cout<<tt1<<tt2<<tt3<<tt4;
	return 0;
}

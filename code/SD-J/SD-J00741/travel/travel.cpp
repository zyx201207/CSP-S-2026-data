#include<bits/stdc++.h>
using namespace std;
bool f[10]={0};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		f[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			f[1]=1;	
			if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C'))
			{
				if(abs(s1[2]-s2[2])==1)
					f[3]=1;
				f[2]=1;
			}
		}
		
	}
	for(int i=0;i<4;i++)
	{
		cout<<f[i];
	}
	return 0;
 } 

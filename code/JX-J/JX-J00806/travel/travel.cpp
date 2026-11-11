#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
bool bj[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{ 
		bj[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{ bj[2]=1;
		if((s1[2]<='C'&&s1[2]>='A')&&(s2[2]<='C'&&s2[2]>='A'))
	    {
			bj[3]=1;
			if(s1[2]==s2[2]+1||s1[2]+1==s2[2]) bj[4]=1;
	    }
	    else
	    {
			if((s1[2]<='F'&&s1[2]>='D')&&(s2[2]<='F'&&s2[2]>='D'))
			{
				bj[3]=1;
				bj[4]=1;
			}
		}
		
			
			}
		
	}
	for(int i=1;i<=4;i++)
	{
		cout<<bj[i];
	}
	return 0;
}

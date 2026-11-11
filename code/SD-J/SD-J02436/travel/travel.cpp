#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag1=false,flag2=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		flag1=true;
	}
	
	if(flag1==false)//如果在同一节车厢 再继续判断 否则后面全部是0 
	{
		cout<<"1";
		
		for(int i=0;i<2;i++)
		{
		if(s1[i]!=s2[i])
		flag2=true;
		}
	
		if(flag2==false)//如果同车厢 同排 再继续判断 否则后面全部是0 
		{
			cout<<"1";
		
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
			{
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
				{
					cout<<"1";
			
					if(abs(int(s1[2])-int(s2[2]))==1)
					cout<<"1";
					else
					cout<<"0";
				}
				else
				cout<<"00";
			}
			else 
			{
				if(s2[2]=='D'||s2[2]=='F')
				{
					cout<<"1";
			
					if(abs(int(s1[2])-int(s2[2]))==1)
					cout<<"1";
					else
					cout<<"0";
				}
				else
				cout<<"00";
			}
		}
	else
	cout<<"000";
	
	}
	else
	cout<<"0000";
	
	
	
	
	return 0;
}

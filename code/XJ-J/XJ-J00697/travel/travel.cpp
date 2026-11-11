#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char a=s1[2],b=s2[2];
	
	if(c1==c2)//两张车票对应的座位是否在同一节车厢
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])//两张车票对应的座位是否在同一节车厢的同一排
		{
			cout<<"1";
			if(a<='C'&&b<='C'||a>='D'&&b>='D')//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
			{
				cout<<"1";
				if(a<='C'&&b<='C')
				{
					if(a>='A'&&a<='B'&&b>='A'&&b<='B')
					{
						cout<<"1";
					}else if(a>='B'&&a<='C'&&b>='B'&&b<='C')
					{
						cout<<"1";
					}else
					{
						cout<<"0";
					}
					
					
				}else
				{
					cout<<"1";
				}
			}else
			{
				cout<<"00";
			}
		}else
		{
			cout<<"000";
		}
		
	}else
	{
		cout<<"0000";
	}
	
	
	return 0;
}
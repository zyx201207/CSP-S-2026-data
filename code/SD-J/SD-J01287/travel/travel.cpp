#include<bits/stdc++.h>
using namespace std;
bool pd(char a,char b)
{
	if(a<'D'&&b<'D')
	{
		if(abs((int)(a-b))==1)return 1;
		return 0;
	}
	else if(a>'C'&&b>'C')return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int lens1=s1.size(),lens2=s2.size();
	string ans="1111";
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	int flag=1;
	for(int i=0;i<3;i++)
	{
		if((s1[i]<='9'&&s1[i]>='0')&&(s2[i]<='9'&&s2[i]>='0'))
		{
			if(s1[i]!=s2[i])
			{
				flag=0;
				break;
			}
		}
	}
	if(!flag)
	{
		cout<<"1000";
		return 0;
	}
	if((s1[lens1-1]<'D'&&s2[lens2-1]>'C')||(s1[lens1-1]>'C'&&s2[lens2-1]<'D'))
	{
		cout<<"1100";
		return 0;
	}
	if(!pd(s1[lens1-1],s2[lens2-1]))cout<<"1110";
	else cout<<"1111";
}//Trick||Treat!

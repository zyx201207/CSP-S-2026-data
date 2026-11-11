#include<bits/stdc++.h>
using namespace std;
bool fir=0,sec=0,thi=0,fou=0;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",&c1,&s1,&c2,&s2);
	cin>>c1>>s1>>c2>>s2;
	
	s1[2]-='A',s2[2]-='A';
	if (c1!=c2)
	{
		cout<<"0000";
	}
	else if (s1[0]+s1[1]!=s2[0]+s2[1])
	{	
		cout<<"1000";
	}
	
	else if ((s1[2]<=2&&s2[2]>=3)||(s1[2]>=3&&s2[2]<=2))
	{
		cout<<"1100";
	}
	else if (abs(s1[2]-s2[2])!=1)
	{
		cout<<"1110";
	}
	else {
		cout<<"1111";
	}
	return 0;
}

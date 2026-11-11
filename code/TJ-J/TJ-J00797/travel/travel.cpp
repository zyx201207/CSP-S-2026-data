#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
bool ok1,ok2,ok3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		ok1=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&ok1==1)
	{
		ok2=1;
		cout<<1;
	}
	else 
	{
		cout<<0;
	}
	int ans1=(int)s1[2]-'A'+1,ans2=(int)s2[2]-'A'+1;
	if((ans1>=1&&ans1<=3&&ans2>=1&&ans2<=3&&ok2==1)||(ans1>=4&&ans2>=4&&ok2==1))
	{
		ok3=1;
		cout<<1;
	}
	else 
	{
		cout<<0;
	}
	if(ok3==1)
	{
		if((ans1==1&&ans2==3)||(ans1==3&&ans2==1)) 
		{
			cout<<0;
		}
		else 
		{
			cout<<1;
		}
	}
	else 
	{
		cout<<0;
	}
	return 0;
 } 

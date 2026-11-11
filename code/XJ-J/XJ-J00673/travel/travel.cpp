//Trick||Treat!
#include<bits/stdc++.h>
using namespace std;
long long int i,a1,a2,ans;
char c1[5],c2[5],s1[5],s2[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	cout<<"1";
	else
	{
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	cout<<"1";
	else
	{
		cout<<"0"<<"0"<<"0";
		return 0;
	}
	a1=s1[2]-'A';
	a2=s2[2]-'A';
	if(a1>=0&&a1<=2&&a2>=0&&a2<=2||a1==3&&a1==5&&a2==3&&a2==5)
	cout<<"1";
	else
	{
		cout<<"0"<<"0";
		return 0;
	}
	ans=max(a1,a2)-min(a1,a2);
	if(a1>=0&&a1<=2&&ans==-1||ans==1&&a1>=0&&a1<=2)
	{
		cout<<"1";
		return 0;
	}
	else
	{
		if(a1>=3&&a1<=5&&ans==2||a1>=3&&a1<=5&&ans==-2)
		cout<<"1";
		else
		cout<<"0";
	}
	return 0;
}
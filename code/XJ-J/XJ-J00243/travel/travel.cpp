#include <bits/stdc++.h>
using namespace std;
int c1,s1[5],c2,s2[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2;
	for(int i=1;i<=5;i++)
	{
		cin>>s1[i];
		cin>>s2[i]; 
	} 
	int sum=s1[2];
	int num=s2[2];
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<11;
		if(sum==num)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else 
	{
		cout<<100;
	}
	cout<<0;
}

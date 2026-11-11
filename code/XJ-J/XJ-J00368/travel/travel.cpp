#include<bits/stdc++.h>
using namespace std;
char s1,c1,s2[2],c2[2];
int main()
{
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	cin>>c1;
	for(int i=0;i<2;i++)
	{
		cin>>c2[i];
	}
	cin>>s1;
	for(int j=0;j<2;j++)
	{
		cin>>s2[j];
	}
	if(c1!=s1)
	{
		cout<<"0000";
		return 0;
	}
	if(c2[0]!=s2[0]||c2[1]!=s2[1])
	{
		cout<<"1000";
		return 0;
	}
	if(c2[2]-s2[2]>1)
	{
		cout<<"1100";
		return 0;
	}
	if((c2[2]=='C'||c2[2]=='D')&s2[2]!='B')
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
}
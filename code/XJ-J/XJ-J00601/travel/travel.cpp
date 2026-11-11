#include<bits/stdc++.h>
using namespace std;
string s1,s2;
long long int c1,c2,i,ans[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	 ans[1]=1;
	else
	 ans[1]=0;
	for(i=1;i<2;i++)
	{
		if(s1[i]==s2[i]&&s1[i+1]==s2[i+1])
		 ans[2]=1;
		else
		 ans[2]=0;
		if(s1[i+2]<='D'&&s1[i+2]>='F'&&s2[i+2]<='D'&&s2[i+2]<='F'||s1[i+2]<='A'&&s1[i+2]>='C'&&s2[i+2]<='A'&&s2[i+2]<='C')
		 ans[3]=1;
		else
		 ans[3]=0;
		if(s1[i+2]-s2[i+2]=='-1'||s1[i+2]-s2[i+2]=='1')
		 ans[4]=1;
		else
		 ans[4]=0;
	}
	for(i=1;i<=4;i++)
	 cout<<ans[i];
	 
	return 0;
} 

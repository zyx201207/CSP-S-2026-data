#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;	
bool b1,b2,b3,b4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)b1=1;
	if(b1==1&&s1[0]==s2[0]&&s1[1]==s2[1])b2=1;
	if(b2==1)
	{
		if(s1[2]<68&&s2[2]<68)
		{
			b3=1;
			if(s1[2]<s2[2]&&s2[2]-s1[2]==1)b4=1;
			else if(s1[2]>s2[2]&&s1[2]-s2[2]==1)b4=1;
		}
		else if(s1[2]>=68&&s2[2]>=68){
			b3=1;
			if(s1[2]<s2[2]&&s2[2]-s1[2]==2)b4=1;
			else if(s1[2]>s2[2]&&s1[2]-s2[2]==2)b4=1;
		}
	}
	cout<<b1<<b2<<b3<<b4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
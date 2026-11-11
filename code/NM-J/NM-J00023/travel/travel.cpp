#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long n,m,i,j,x,y,t,a1=0,a2=0,a3=0,a4=0,cnt=0,ans=0;
	string s1,s2;
	cin>>n>>s1>>m>>s2;
	if(n==m) 
	{
		a1++;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) 
		{
			a2++;
			if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C')) 
			{
				a3++;
				if(char(s1[2]+1)==s2[2]||char(s1[2]-1)
				==s2[2]||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) a4++;
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
//02 01D 02 01F

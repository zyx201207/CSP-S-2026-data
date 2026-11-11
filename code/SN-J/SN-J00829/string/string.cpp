#include<bits/stdc++.h>
using namespace std;
int main()
{
//姚元辰 SN-J00829 延安职业技术学院附属中学 
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	long long a,z,sum=0,sun=0;
	string s;
	for(int i=1;i<=a;i++)
	{
		cin>>z;
		for(int j=1;j<=z;j++)
		{
			cin>>s;
		}
	}
	for(int w=1;w<a*z;w++)
	{
		for(int t=a*z;t>=1;t--)
		{
			if(s[w]==s[t])
			{
				sum++;
			}
		}
	}
	cout<<a*z-sum;
}

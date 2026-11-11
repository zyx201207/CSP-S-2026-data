#include<bits/stdc++.h>
using namespace std;
int n,a,t,m;
string s,ans,s1;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
			ans=c+ans;
		}
		m+=a;
	}
	for(int i=0;i<m;i++)
	{
		if(s[i]!=ans[i])
		{
			ans[i]=s[i];
			t++;
			s1="";
			for(int j=0;j<m;j++)
			{
				s1=ans[j]+s1;
			}
			if(ans==s1)
			{
				cout<<t;
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
}


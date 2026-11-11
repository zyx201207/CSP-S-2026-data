#include<bits/stdc++.h>
using namespace std;
long long int n,a,o;
char b;
string s,k;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		for(int j=1;j<=a;j++)
		{
			s+=b;
		}
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		k+=s[i];
	}
	if(s==k)
	{
		cout<<"0";
	}
	else
	{
		while(s!=k)
		{
			for(int i=0;i<s.size();i++)
			{
				if(s[i]!=s[s.size()-1-i])
				{
					s[s.size()-1-i]=s[i];
					o++;
					break;
				}
			}
			k="";
			for(int i=s.size()-1;i>=0;i--)
			{
				k+=s[i];
			}
		}
		cout<<o;
	}
	
	return 0;
}
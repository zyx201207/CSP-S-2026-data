#include <bits/stdc++.h>
using namespace std;
string d,s;
int a,cnt=0;
long long n;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int b=1;b<=a;b++)
		{
			s[i]+=c;
			d[i]=s[i];
		}	
	}
	for(int i=1;i<=s.size();i++)
	{
		for(int j=s.size();j>=i;j--)
			if(s[i]!=s[j]) 
			{
				cnt++;
			}
	}
	cout<<cnt/2;
	return 0;
}
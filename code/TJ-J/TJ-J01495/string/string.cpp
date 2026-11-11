#include <iostream>
using namespace std;
long long n,a;
string c,s;
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
		} 
	}
	long long l=s.length(),ans=0;
	for(long long i=1;i <=l;i++)
	{
		if(s[l-1-i]!=s[i])
		{
			s[l-1-i]=s[i];
			ans++;
		}
	}
	cout <<ans;
	return 0;
 } 


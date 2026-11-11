#include<bits/stdc++.h>
using namespace std;
long long a[250000];
char r[250000];
int n;
	string s;
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);

	//cin>>s;
//	cout<<s[10000];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i]>>r[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=r[i];
		}
	}
	long long ans=0;
	int len=s.size();
	int len1;
	if(len%2==0)
	{
		len1=len/2;
	}
	else
	{
		len1=(len-1)/2;
	}
	for(int i=1;i<=len1;i++)
	{
		if(s[i]==s[len+1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

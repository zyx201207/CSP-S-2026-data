#include<bits/stdc++.h>
using namespace std;
int a[200005];
string c[200005],s[9999995];
int main()
{
	freopen("string.in","r",stdin);
	freopen("stding.out","w",stdout);
	int n;
	cin>>n;
	int s2=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=s2;j<s2+a[i];j++)
		{
			s[j]=c[i];
		}
		s2=s2+a[i];
	}
	int j=1,s1=0;
	for(int i=n;i>=1;i--)
	{
		if(s[i]!=s[j]) s1++;
		j++;
	}
	cout<<s1;
	return 0;
}
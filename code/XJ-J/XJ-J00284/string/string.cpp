#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string l,l1,s1,s2;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			l+=c[i];
		}
	}
	l1=l;
	reverse(l1.begin(),l1.end());
	if(l1==l)
	{
		cout<<ans;
		return 0;
	}
	else
	{
		long long len=l.size()-1,o=0;
		while(o<len)
		{
			if(l[o]!=l[len])
			{
				l[len]=l[o];
				ans++;
			}
			o++;
			len--;
		}
	}
	cout<<ans;
	return 0;
}
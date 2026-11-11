#include <bits/stdc++.h>
using namespace std;
int n,ans=0,maxc=-1,a[200005];
char c[200005];
string s1="",s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		maxc=max(maxc,a[i]);
	}
	long long check=maxc*n;
	if(check<=1e7)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
				s1+=c[i];
		}
		s2=s1;
		reverse(s1.begin(),s1.end());
		if(s1==s2)
		{
			cout<<0;
			return 0;
		}
		string s=s2;
		int len=s.size();
		for(int i=0;i<len/2+1;i++)
		{
			if(s[i]!=s[len-i])
				ans++;
		}
		cout<<ans;
	}
	else
	{
		if(c[1]==c[n])
			cout<<0;
		else
			cout<<1;
	}
	return 0;
}

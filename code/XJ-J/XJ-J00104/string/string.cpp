#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,m,l,ans1,ans2,a[666666];
string s1,s2,s,x;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>x;
		for(j=1;j<=a[i];j++)
		s+=x;
	}
	l=s.size();
	if(l%2)
	{
		for(i=0,j=l-1;i<l/2,j>l/2;i++,j--)
		{
			if(s[i]!=s[j])
			ans1++;
		}
		cout<<ans1;
		return 0;
	}
	else
	{
		for(i=0,j=l-1;i<l/2,j>=l/2;i++,j--)
		{
			if(s[i]!=s[j])
			ans2++;
		}
		cout<<ans2;
		return 0;	
	}
}
/*
2
2 a
3 a
3
2 a
2 b
1 c
*/

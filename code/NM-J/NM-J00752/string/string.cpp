#include<bits/stdc++.h>
using namespace std;
string a[300000],c[300000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("strig.out","w",stdout);
	int i,j,n,q,s=0,ss=0;
	char b;
	cin>>n;
	if(n==1)
	{
		cout<<'0';
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		cin>>q;
		s+=q;
		for(j=1;j<=q;j++)
		{
			cin>>b;
			a[j]=b;
		}
	}
	for(j=1;j<=s;j++)
	{
		i=s;
		c[j]=a[i];
		i--;
	}
	for(j=1;j<=q;j++)
	{
		ss=q;
		if(a[j]==c[j])
		{
			ss--;
		}
		if(ss==0)cout<<'0';	
	}
	if(ss==0)cout<<'0';
	return 0;
}

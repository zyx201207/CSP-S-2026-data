#include<bits/stdc++.h>
using namespace std;
long long a[101000],q=0,f=1,ans=0;
char b[101000],w1[101000],w2[101000],s[101000];
int n;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(b[i]!=b[i-1]&&i!=1)f=0;
	}
	if(n<=2)
	{
		if(b[1]==b[2]){cout<<0;return 0;}
		else{cout<<min(a[1],a[2]);}
	}
	if(f==1){cout<<0;return 0;}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s[ans++]=b[i];
		}
	}
	for(int i=1;i<=ans;i++)
	{
		if(s[i]!=s[ans-i+1])q++;
	}
	cout<<q;
	return 0;
}

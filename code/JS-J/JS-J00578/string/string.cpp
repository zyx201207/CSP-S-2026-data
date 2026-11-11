#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long b;
	char c;
	long long s=0;
	cin>>n;
	long long a[n+5];
	long long k=1;
	if(n==1)
	{
		cin>>b>>c;
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b>>c;
		for(int j=k;j<=k+b-1;j++)
		{
			a[j]=c;
		}
		k+=b;
	}
	k--;
	for(int i=1;i<=k/2;i++)
	{
		if(a[i]!=a[k-i+1])
			s++;
	}
	cout<<s;
	return 0;
}

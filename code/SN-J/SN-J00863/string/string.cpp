#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,a[100005],ans=0;
	char s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>s;
		for(int j=1;j<=x;j++)
	    {
		    a[j]=s;
		    ans++;
	    }
	}
	int b[100005],f=0;
	for(int i=ans;i>=1;i--)
	{
		f++;
		b[f]=a[i];
	}
	int sum=0;
	for(int i=1;i<=ans;i++)
	{
		if(b[i]!=a[i])
		{
			sum++;
		}
	}
	cout<<(sum/2);
	return 0;
}


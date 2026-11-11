#include<bits/stdc++.h>
using namespace std;
long long a[20000005];
char c[200000005];
char S[1000000005];
long long n;
long long ans=0;
long long x=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			S[j+ans]=c[i];
	    }
	    ans=ans+a[i];
	}
	for(int k=1;k<=ans/2;k++)
	{
		if(S[k]!=S[ans-k+1])
		{
			x++;
		}
	}
	cout<<x;
    return 0;	
}

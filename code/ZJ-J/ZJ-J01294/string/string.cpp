#include<bits/stdc++.h>
using namespace std;
int n;
long long a1[200005],a2[200005],len,ans=0;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i]>>c[i];
		len+=a1[i];
		a2[i]=a2[i-1]+a1[i];
		a1[i]=a2[i-1]+1;
	}
	long long len2=len/2;
	for(int i=1;i<=n;i++)
	{
		if(a1[i]<=len2)
		{
			long long x1=len-a1[i]+1,x2=len-a2[i]+1;
			for(int j=n;j>i;j--)
				if(a1[j]<=x1&&a2[j]>=x2&&c[j]!=c[i])
					ans+=(min(x1,a2[j])-max(x2,a1[j])+1);
					
		}
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[100000005];
string c,sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,h=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=c.size();
	for(int i=1;i<=l;i++)
	{
		sum+=a[i]*c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=1;j--)
		{
			if(sum[i]!=sum[j])
			{
				h++;
			}
		}
	}
	cout<<h;
	return 0;
}
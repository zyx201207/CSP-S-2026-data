#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int b[200005][40];
int t[40],hou[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		long long x=(1ll<<30);
		for(int j=30;j>=0;j--)
		{
			b[i][j]=a[i]%(x*2)/x;
			t[j]+=b[i][j];
			x/=2;
		}
	}
	long long max=0;
	for(int i=30;i>=0;i--)
	{
		if(m<=t[i])
		{
			for(int j=1;j<=n;j++)
			{
				if(b[j][i]==0&&hou[j]==0)
				{
					hou[j]=1;
					for(int k=i;k>=0;k--)
						t[k]-=b[j][k];
				}
			}
			max+=(1ll<<i);
		}
	}
	cout<<max;
	return 0;
}

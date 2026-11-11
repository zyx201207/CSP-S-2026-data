#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],i,j,z[40],c[40],k;
bitset<40>b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(j=31;j>=0;j--)
	{
		for(i=1;i<=n;i++)
		{
			z[j]+=b[i][j];
		}
	}
	for(j=31;j>=0;j--)
	{
		if(z[j]<m)c[j]=0;
		else if(z[j]>=m)
		{
			c[j]=1;
			for(i=1;i<=n;i++)
			{
				if(b[i][j]==0)
				{
					for(k=31;k>=0;k--)
					{
						z[k]-=b[i][k];
						b[i][k]=1;
					}
				}
			}
		}
	}
	k=0;
	for(j=31;j>=0;j--)
	{
		k=k*2+c[j];
	}
	cout<<k;
	return 0;
}
/*

4 2
3 15 12 12

1111
1100
1100
0011
3322

5 3
31 3 1 15 7

00001
00011
00111
01111
11111
12345

3 2
14 15 16

01110
01111
10000

111110
111101
111011
110111
543333
4

3322

*/
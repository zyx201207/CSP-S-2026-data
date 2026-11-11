#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[3005][3005],ff,fff,gs[10];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=4)fff=1;
		if(pow(2,log2(a[i]+1))-1!=a[i])ff=1;
	}
	sort(a+1,a+n+1);
	if(!ff)
	{
		cout<<a[n-m+1];
		return 0; 
	}
	if(!fff)
	{
		for(int i=1;i<=n;i++)
		{
			gs[a[i]]++;
		}
		if(gs[3]>=m)
		{
			cout<<3;
		}
		else if(gs[3]+gs[2]>=m)
		{
			cout<<2;
			
		}
		else
		{
			cout<<1;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j==1)
			{
				f[i][j]=a[i];
			}
			else f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
		}
	}
	cout<<f[n][m];
	return 0; 
 } 
 /*
 3
2 a
2 b
1 c
*/

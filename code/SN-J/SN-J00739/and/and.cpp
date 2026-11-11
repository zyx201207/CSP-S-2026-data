//谢震寰 西安市第三中学 SN-J00739 
#include <bits/stdc++.h>
using namespace std;
int a[1100100][25],b[25];
int ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for(int i=0;i<n;i++) cin >>b[i];
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>>j&1)
			{
				a[i][j]=1;
			}
			else a[i][j]=0;
		}
	}
	for(int i=0;i<(1<<n);i++)
	{
		int sum=0,cnt=b[0];
		for(int j=0;j<n;j++)
		{
			sum+=a[i][j];
		}
		if(sum==m)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]==1)
				{
					cnt=cnt and b[j];
					
				}
			}
		}
		ans=max(ans,cnt);
	}
	cout <<ans<<'\n';
	return 0;
}


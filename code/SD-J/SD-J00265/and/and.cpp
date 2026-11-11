#include<bits/stdc++.h>
using namespace std;
int a[4][200200],n,m,zz=1,num,ans,zz1,zz2;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	zz1=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[1][i];
	}
	for(int i=29;i>=0;i--)
	{
		num=0,zz2=0;
		int sz=pow(2,i);
		for(int j=1;j<=zz1;j++)
		{
			if((a[zz][j]%(sz*2))/sz==1)num++;
		}
		if(num>=m)
		{
			ans+=sz;
			for(int j=1;j<=zz1;j++)
			{
				if((a[zz][j]%(sz*2))/sz==1)a[3-zz][++zz2]=a[zz][j];
			}
			zz=3-zz;
			zz1=zz2;
		}
	}
	cout<<ans;
	return 0;
}

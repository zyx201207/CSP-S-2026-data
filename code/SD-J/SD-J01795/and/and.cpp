#include<bits/stdc++.h>
using namespace std;
long long n,m,A[300000],num,a,b,c,W[300000],C[2000],ans,z;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long i,j,k,l;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>A[i];
		num=max(num,A[i]);
	}
	if(m==1)
	{
		cout<<num;
	}
	else if(m==2)
	{
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				if(j==i)continue;
				z=A[i]&A[j];
				ans=max(ans,z);
			}
		}
		cout<<ans;
	}
	else if(m==n)
	{
		ans=A[1];
		for(i=2;i<=n;i++)
		{
			ans=ans&A[i];
		}
		cout<<ans;
	}
	else if(m==3)
	{
		for(i=1;i<=n-2;i++)
		{
			for(j=i+1;j<=n-1;j++)
			{
				for(k=j+1;k<=n;k++)
				{
					z=A[i]&A[j];
					z=z&A[k];
					ans=max(ans,z);
				}
			}
		}
		cout<<ans;
	}
	else
	{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
